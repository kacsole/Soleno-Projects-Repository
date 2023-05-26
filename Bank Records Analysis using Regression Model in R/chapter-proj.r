install.packages("ggplot2")
install.packages("dplyr")
install.packages("caTools")    # For Linear regression

library(caTools)
library(ggplot2)
library(dplyr)

# Read the bank-full.csv data set
data <- read.csv("bank-full.csv", sep=';')

print(head(data))

# ask for a summary of the data
summary(data)

# correlation of duration, campaign, balance, and previous
print(cor(data[, c('duration','campaign','balance','previous')]))

# splitting of data
split <- sample.split(data, SplitRatio = 0.8) 
split 

train <- subset(data, split == "TRUE") 
test <- subset(data, split == "FALSE")

dim(train)
print(head(train))

dim(test)
print(head(test))

model <- lm(duration ~ campaign + balance + previous, data = train)
summary(model)

# Make a scatter plot of duration vs. campaign
durvscamp <- ggplot(data = data) +
  aes(x = campaign, y = duration) +
  geom_jitter() +
  geom_smooth(method='lm', col="red") + ggtitle("duration vs. campaign")

durvscamp

# Make a scatter plot of duration vs. balance
durvsbal <- ggplot(data = data) +
  aes(x = balance, y = duration) +
  geom_jitter() +
  geom_smooth(method='lm', col="red") + ggtitle("duration vs. balance")

durvsbal

# Make a scatter plot of duration vs. previous
durvsprev <- ggplot(data = data) +
  aes(x = previous, y = duration) +
  geom_jitter() +
  geom_smooth(method='lm', col="red") + ggtitle("duration vs. previous")

durvsprev

# Compute the model without using the training data
model <- lm(duration ~ campaign + balance + previous, data = data)
summary(model)

# ask for confidence intervals for the model coefficients
confint(model, conf.level=0.95)
