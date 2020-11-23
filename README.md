# Data-Pre-Processing
Data class for data pre-processing in mlpack

### What is the desired addition or change?

As discussed a bit in the [PR](https://github.com/mlpack/examples/pull/137). I suggested the idea of adding some data processing functionality to mlpack. 

I compiled a list of features that can be implemented: 
- [x] **info()**: Already implemented, I was thinking maybe we could add the count of non-null values in front of each attribute, let me know if you guys think it's useful.
- [x] **describe()**: This will return `count` `mean` `std` `25%` `50%(median)` `75%` `max` `min` we can take help of armadillo to implement this method. [this](http://arma.sourceforge.net/docs.html#stats_fns) and [this](http://arma.sourceforge.net/docs.html#running_stat)
- [ ] **hist()**: To get the feel of the data, we can either plot it attributes wise or calling a single method which will plot a histogram for all numerical values. We can use [this](https://github.com/lava/matplotlib-cpp) to plot histograms. Just a single file so easy to handle the dependency. 
- [x] A method to find the data type of the attributes. Also if it is categorical then we might need to convert it into numerical values, a function for that will also be helpful. 

I will be adding more features to the list, this seems good enough to get started.
### What is the motivation for this feature?

Loading and creating models is just a part of Machine Learning. The time we invest in understanding data is very important. Based on the nature and properties of datasets we can decide which model to implement. 
My goal is also to create a `Getting Started with ML with mlpack` tutorial, where I will explain everything from feature engineering to model selection to model accuracy. I think this will be a very good starting point for many users. So to make the process more fluid I am planning to implement certain functions to include functionality that would give info about datasets. Like `.info()` `.describe()` from `pandas`

 
### If applicable, describe how this feature would be implemented.

I have already implemented a bit. Check [data.cpp](https://github.com/heisenbuug/Data-Pre-Processing/blob/main/data.cpp)

Output

![Capture](https://user-images.githubusercontent.com/32970979/99764257-ad38df00-2b22-11eb-9b72-3a16f7220347.PNG)
 

### Additional information?

There are some points which we need to discuss before starting the implementation. My concerns:
* Currently I made a class `Data`, so to access `.info()` we have to initialize the object of `Data`, I hope the new class won't be a problem. Although I think this is a decent way to initialize, I am open to any better design suggestions.

* Where to put this class exactly.

* Before starting I think we should list down some basic features so that I can start working and then keep discussing more possible features.


