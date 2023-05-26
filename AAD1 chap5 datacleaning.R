# ========================================================================================================
# Purpose:      Rscript for Data Cleaning demo
# Author:       Chew C.H.
# DOC:          10-09-2017
# Topics:       Data Cleaning; Data Preparation.
# Packages:     data.table
# Data Sources:  
#  1. Example dataset "children.csv"
#  2. Derived Sample from USA Census PUMS Data for Health Insurance Coverage. Already Used in wk 3.
#=========================================================================================================

library(data.table)
setwd('C:/Users/User/Documents/Mapua/Third Year - 3rd Term/CS174 BM2 DATA SCIENCE 4/Submissions/M2-FA1')

children.dt <- fread('children.csv')
children.dt
sum(is.na(children.dt))    ## only 1 NA in dataset
which(is.na(children.dt))  ## That one NA is in row 6 [i.e. value coded: NA]
## Source data has 9 different codes for missing value but only one code is auto-recognized by R.


# Use na.strings to define all human codes for missing values to be NA.
children2.dt <- fread('children.csv', na.strings = c("NA", "missing", "N/A", -99, "", "m", "M", "na", "."))
children2.dt  ## All the 9 ways to code missing value are now recoded as NA.
sum(is.na(children2.dt))    ## 9 NAs in dataset
which(is.na(children2.dt))  
which(is.na(children2.dt$children))  # where are the NAs in children column.
which(is.na(children2.dt$Room))      # where are the NAs in Room column.

