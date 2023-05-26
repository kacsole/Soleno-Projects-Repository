library(dplyr)
library(rpart)
library(rpart.plot)
library(Metrics)
library(mlr)
library(ggplot2)
library(plotly)
library(magrittr) 
library(caTools)
library(ggcorrplot)
library(corrplot)

# Set a working directory to store all the related datasets and files
setwd("C:/Users/User/Documents/Mapua/Third Year - 3rd Term/CS174 BM2 DATA SCIENCE 4/Submissions/M1-SA")

## Reading the Dataset ##
# Import the Housing.csv dataset using the read.csv() function
housing <- read.csv("Housing.csv")

## Data Cleaning and Preparation ##
dim(housing)

# Convert data to numeric
housing$mainroad <- as.numeric(factor(housing$mainroad))
housing$guestroom <- as.numeric(factor(housing$guestroom))
housing$basement <- as.numeric(factor(housing$basement))
housing$hotwaterheating <- as.numeric(factor(housing$hotwaterheating))
housing$airconditioning <- as.numeric(factor(housing$airconditioning))
housing$furnishingstatus <- as.numeric(factor(housing$furnishingstatus))
head(housing)

#clean unnecessary variables
housing_clean <- housing %>%
  select(-c(prefarea)) #Removing Unnecessary Variables
head(housing_clean)

## Identifying independent and dependent variables ##
pairs(housing_clean)

## Splitting data into Train and Test into 70/30 ##
housing_clean['row_id'] = rownames(housing_clean)

set.seed(123)
train_data <- housing_clean %>%
  sample_frac(0.7)

test_data <- housing_clean %>%
  anti_join(train_data, by='row_id')

# Drop row_id from both dataframes
train_data[,'row_id'] <- NULL
test_data[,'row_id'] <- NULL

dim(train_data) 
dim(test_data)

## Decision Tree with default parameters ##
d.tree = rpart(train_data$price~., data=train_data)

rpart.plot(d.tree)
  
## Predicting with test set ##
predict_price <- predict(d.tree, test_data)
table_price <- table(test_data$price, predict_price)
#Printing confusion matrix
print(table_price)

accuracy(test_data$price, predict_price)
accuracy_Test <- sum(diag(table_price)) / sum(table_price)
print(paste('Accuracy for test', accuracy_Test))

# hyperparameter tune
d.tree.params <- makeClassifTask(
  data=train_data, 
  target="price"
)

param_grid_multi <- makeParamSet( 
  makeDiscreteParam("maxdepth", values=4:5),
  makeNumericParam("cp", lower = 0.009, upper = 0.01),
  makeDiscreteParam("minsplit", values=5:10),
  makeDiscreteParam("minbucket", values=0:5),
  makeDiscreteParam("xval", values=0:5)
)

# Define Grid
control_grid = makeTuneControlGrid()

# Define Cross Validation
resample = makeResampleDesc("CV", iters = 3L)

# Define Measure
measure = acc

dt_tuneparam_multi <- tuneParams(learner='classif.rpart', 
                                 task=d.tree.params, 
                                 resampling = resample,
                                 measures = measure,
                                 par.set=param_grid_multi, 
                                 control=control_grid, 
                                 show.info = TRUE)

## Extracting best Parameters from Multi Search ##
best_parameters_multi = setHyperPars(
  makeLearner("classif.rpart", predict.type = "prob"), 
  par.vals = dt_tuneparam_multi$x
)

best_model_multi = train(best_parameters_multi, d.tree.params)

## Predicting the best Model ##
results <- predict(best_model_multi, task = d.tree.params)$data
accuracy(results$truth, results$response)

# decision tree with best hyperparameters
best.d.tree = rpart(train_data$price~., 
                      data=train_data, 
                      control = c(maxdepth = 4, cp=0.00933, minsplit = 10, minbucket = 3, xval = 0))

rpart.plot(best.d.tree)