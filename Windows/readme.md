## <center> Picture Change With OpenCV 
#### <center>platform: Windows 10</center>
#### Description
you can open the PicChange.exe to test this function. input the paths of two pictures, pay attention to use // or \ in the paths
<br/>
### 1. Install OpenCV
+ download OpenCV install program form [OpenCV official website](https://opencv.org)
+ follow the guidance to unzip OpenCV, remember the extract path you set

### 2. Configure environment variables
+ My Computer -> right click Property -> Advanced System Settings -> select Advanced -> Environment Variables -> System Variables -> find Path in System Variables -> add path, such as D:\\opencv\\build\\x64\\vc14\\bin

### 3. Configure paths in Visual Studio
+ Using the Project -> Settings. menu item. Click the C/C++ tab and select Preprocessor from the Category drop-down list. Enter the path of include in the "Additional include directories", such as: D:\\opencv\\build\\include\\opencv or D:\\opencv\\build\\include\\opencv\\opencv2 (depend on your header file include use `#include <opencv2\opencv.hpp>` or `#include <opencv.hpp>`)  

+ Select the Link tab from the Same Settings dialog box. Choose Input from the Category drop-down list. Add the lib path to the "Additional library path", such as: D:\\opencv\\build\\x64\vc14\lib

+ Also add "opencv\_world411.lib" to the "Object/library modules" line. Be sure that the name is separated by a space. the .lib file will be find in D:\\opencv\\build\\x64\vc14\lib. if you use Debug type rather than Release, add "opencv\_world411d.lib"
