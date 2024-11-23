# Drawing_features
 My library with useful drawing features on SDL

## How to use it?

### Installation instructions

Clone the repository. In the repository folder write this:

```shell
cmake .
sudo make install
```

Now you`re ready to use this library in your projects

### Using with cmake
To use this library with cmake, you need to write this commands in right places of your CMakeLists.txt:

```c
find_package(DrawingFeatures REQUIRED)

target_include_directories(Balls PRIVATE ${DrawingFeatures_INCLUDE_DIRS})
target_link_libraries(Balls PRIVATE DrawingFeatures::DrawingFeatures)
```

## Examples
**TODO: do an example folder right in library**