# ComputePipeline
A C++20 single-file header-only cross platform compute pipeline.

## Install
Just include the ComputePipeline.hpp file in your code.

## Usage
ComputePipeline uses fonctions called **actions**. These actions have only one parameter.
The ComputePipeline constructor requires you to provide an initial action.
The parameter's type of the initial action will be used as parameter type for the `compute` method.
You can add several actions thanks to the `addAction` method. ComputePipeline only support one action per input type.
The result of each actions will be used for a next action if its input type is the same.
If there is no action with the same input type, the compute returns the result of the last action embedded in a `std::any`.

##  Example
Check the example folder or use the "example" CMake target.
