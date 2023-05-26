install.packages("ggplot2")
install.packages("dplyr")

library(ggplot2)
library(dplyr)

# Set a working directory to store all the related data
setwd("C:/Users/Anton/Documents/3Q2223/CS174/Module 2/M2 - FA1.1 Data Structures and Visualization (Chapter Project)")


# Data Structures
# Import data using the read.csv() function and store into a data frame
countries.df <- read.csv("gapminderDataFiveYear.csv")

# Check the structure of the data frame
str(countries.df)

# Provide summary statistics
summary(countries.df)


# Data Visualization
# Scatter Plot

# with regression line
lifeExpvsgdp <- ggplot(countries.df, aes(x=lifeExp, y=gdpPercap, col=continent)) +
  geom_point(aes(color=continent)) + 
  scale_color_manual(values=c('#097054','#FF9900','#6599FF','#FFDE00','#6600CC')) +
  geom_smooth(method='lm', col="#FF0000") + 
  ggtitle("Life Expectancy vs. GDP per capita")

lifeExpvsgdp # outputs the plot

# without regression line
lifeExpvsgdp <- ggplot(countries.df, aes(x=lifeExp, y=gdpPercap, col=continent)) +
  geom_point(aes(color=continent)) + 
  scale_color_manual(values=c('#097054','#FF9900','#6599FF','#FFDE00','#6600CC')) + 
  ggtitle("Life Expectancy vs. GDP per capita")

lifeExpvsgdp


# Bar Chart
gdp_comp <- countries.df %>% group_by(continent) %>% 
  summarise(mean_gdp = mean(gdpPercap, na.rm = TRUE))

gdp_comp

# Average GDP per capita for each continent
ggplot(gdp_comp, aes(x=continent, y=mean_gdp, fill=continent)) +
  geom_bar(stat="identity", position=position_dodge()) + ggtitle("Average GDP per capita for each continent") + theme(plot.title = element_text(hjust = 0.5), axis.text.x = element_text(angle=90, vjust=.5, hjust=1))

# GDP per capita for each continent
ggplot(data=countries.df, aes(x=continent, y=gdpPercap, fill=continent)) +
  geom_bar(stat="identity", position=position_dodge()) + ggtitle("GDP per capita for each continent") + theme(plot.title = element_text(hjust = 0.5), axis.text.x = element_text(angle=90, vjust=.5, hjust=1))


# Box Plot
# Life expectancy for each continent
ggplot(countries.df, aes(x = continent, y = lifeExp, fill = continent)) + geom_boxplot() + 
  ggtitle("Life Expectancy in each Continent") + theme(plot.title = element_text(hjust = 0.5))
