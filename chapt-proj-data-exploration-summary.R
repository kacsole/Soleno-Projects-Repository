install.packages("ggplot2")
install.packages("dplyr")
install.packages("psych")
install.packages("caret")
install.packages("tseries")
install.packages("forecast")

library(ggplot2)
library(dplyr)
library(psych)
library(caret)
library(tseries)
library(forecast)

# Set a working directory to store all the related datasets and files
setwd("C:/Users/Anton/Documents/3Q2223/CS174/Module 1/M1-FA2.1 Chapter Project (Data Exploration and Summary)")

# Import the Data_Train.csv dataset using the read.csv() function
flights.df <- read.csv("Data_Train.csv", stringsAsFactors = TRUE)

# Data Preparation

#Convert date into appropriate format
flights.df$Date_of_Journey = as.Date(flights.df$Date_of_Journey, "%d/%m/%y")

# Remove redundant data
flights.df = subset(flights.df, Airline != "Trujet" & Airline != "Vistara Premium economy" & Airline != "Jet Airways Business" & Airline != "Multiple carriers Premium economy")
table(flights.df$Airline)

# Remove redundant columns
flights.df$Route <- NULL

# Identify missing values
colSums(is.na(flights.df))

# Data Exploration

# Prints the number of rows and columns
dim(flights.df)

# Prints the first few lines of the data on the console
print(head(flights.df))

# Sort the flights in ascending or descending order
flights.df[order(flights.df$Price, flights.df$Airline),]
flights <- flights.df[order(flights.df$Price, flights.df$Airline),]

# Data Summary

# Summarizes the dataset's values
summary(flights.df)


# Data Visualizations

# Plot prices based on the airline
ggplot(data=flights.df, aes(x=Airline, y=Price, fill=Airline)) +
  geom_bar(stat="identity", position=position_dodge()) + ggtitle("Prices based on Airline") + theme(plot.title = element_text(hjust = 0.5), axis.text.x = element_text(angle=90, vjust=.5, hjust=1))

# Plot the price based on Departure Time
ggplot(flights.df, aes(x = Dep_Time, y = Price, fill = Dep_Time)) + geom_boxplot() + 
  ggtitle("Price based on Departure Time") + theme(plot.title = element_text(hjust = 0.5))

ggplot(data=flights.df, aes(x=Dep_Time, y=Price, fill=Dep_Time)) +
  geom_bar(stat="identity", position=position_dodge()) + ggtitle("Price based on Departure Time") + theme(plot.title = element_text(hjust = 0.5), axis.text.x = element_text(angle=90, vjust=.5, hjust=1))

# Plot the price based on Arrival Time have to convert to numbers only
ggplot(flights.df, aes(x = Arrival_Time, y = Price, fill = Arrival_Time)) + geom_boxplot() + 
  ggtitle("Price based on Arrival Time") + theme(plot.title = element_text(hjust = 0.5))

ggplot(data=flights.df, aes(x=Arrival_Time, y=Price, fill=Arrival_Time)) +
  geom_bar(stat="identity", position=position_dodge()) + ggtitle("Price based on Arrival Time") + theme(plot.title = element_text(hjust = 0.5), axis.text.x = element_text(angle=90, vjust=.5, hjust=1))

# Get the maximum price of a flight based on the source and destination of the city
price_comp <- flights.df %>% group_by(Source, Destination) %>% 
  summarise(mean_price = mean(Price, na.rm = TRUE))

# Correlation between destination city, average price and source city
pairs.panels(price_comp[c("Destination", "mean_price", "Source")])
pairs.panels(price_comp[c("Destination", "mean_price", "Source")], method = 'spearman')

# Plot the average price based on source and destination city
ggplot(price_comp, aes(x = Destination, y = mean_price)) + geom_point() + 
  facet_wrap(.~ Source) + ggtitle("Average Ticket Price based on the Source and Destination City") + 
  theme(plot.title = element_text(hjust = 0.5))


# Time Series Model

#Extract data of the Jet Airways airline
timeseries = flights.df[(flights.df$Airline == "Jet Airways"),]

#Examine the average price based on the date of journey
avgPrice_JetAir <- timeseries %>% group_by(Date_of_Journey) %>%
  summarise(mean = mean(Price, na.rm = TRUE))

#Time series Analysis
ts.flightprice = ts(avgPrice_JetAir$mean, start = c(2019,1), frequency = 12)

#Train the ARIMA time series model
ts.model = auto.arima(ts.flightprice, trace = TRUE)

#Forecast the time series model
ts.forecast = forecast(ts.model, h = 12)

#Plot the forecast timeseries graph
plot(ts.forecast, xlab = "Year", ylab = "Price")

summary(ts.model)
accuracy(ts.model)

summary(ts.forecast)
accuracy(ts.forecast)

#Hypothesis Testing using ADF
adf.test(ts.forecast$fitted, alternative = "stationary")
plot(ts.model$residuals, main = "Timeseries Residual")
