## <center> Picture Change With OpenCV 
#### <center>platform: MacOS</center>
#### Description
because OpenCV on MacOS use .dylib, and it's difficult to handle the link in libs, you have to set the paths in Xcode and bulid the executable file by yourself
<br/>
### 1. Install OpenCV
+ install Homebrew  
input in terminal  
`ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`

+ install CMake  
input in terminal  
`sudo brew install cmake`

+ install wget  
input in terminal   
`brew install wget`

+ install OpenCV  
input in terminal   
`brew install opencv`  
OpenCV will be installed at /usr/local/Cellar/opencv

### 2. Configure paths in Xcode
+ open Xcode, choose New -> New Project -> Command Line Tool  

+ Name it and select C++ for type

+ Click on your project from the left menu. Click the build settings tab from the top. Filter all. Scroll to Search Paths. Under header search paths, for debug and release, set the path to /usr/local/Cellar/opencv/4.1.1\_1/include/opencv4/opencv2. Under library search paths, set the path to /usr/local/Cellar/opencv/4.1.1_1/lib. Finally, check if C++ standard library is libstdc++ or not, if not, change it to this!

+ Click on your project from the left menu. File->New->New Group, Name the group OpenCV Frameworks.

+ Select the folder (group) you just labeled, OpenCV Frameworks in the left menu. Go to File -> add Files, Type /, which will allow you to manually go to a folder. Go to -> /usr/local/Cellar/opencv/4.1.1_1/lib

+ Select both of these files, libopencv\_core.dylib, libopencv\_highgui.dylib, and click Add. (you may need to add other library files from this folder to run other code.)

+ You must include this line of code in the beginning of your main.cpp file:  
`#include <opencv.hpp>`  
the header file will be searched at the path you set
