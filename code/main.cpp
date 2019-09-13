#include <opencv.hpp>
#include <ctime>

using namespace cv;
using namespace std;

//#define debug

int main()
{
#ifndef debug
    string picPath1, picPath2;
    cout << "enter the paths of the picture" << endl;
    cout << "pay attention to the length and width of the pictures" << endl;
    cout << "because the bigger one will be scaled down" << endl;
    cout << "The first picture:";
    cin >> picPath1;
    cout << "The second picture:";
    cin >> picPath2;
    cout << "the picture will change in 1 second" << endl;
    Mat pic1 = imread(picPath1);
    Mat pic2 = imread(picPath2);
#endif

#ifdef debug
    Mat pic1 = imread("/Users/shizi9/Desktop/PicBefore.png");
    Mat pic2 = imread("/Users/shizi9/Desktop/PicAfter.png");
#endif
    if (pic1.empty() || pic2.empty()) {
        cout << "Couldn't open image" << endl;
        return -1;
    }
    
    Mat picBefore, picAfter;
    if (pic1.cols < pic2.cols) {
        resize(pic2, picAfter, Size(pic1.cols,pic1.rows));
        picBefore = pic1;
    }
    else{
        resize(pic1, picBefore, Size(pic2.cols,pic2.rows));
        picAfter = pic2;
    }
    
    cout << "press Enter on picture to start" << endl;
    imshow("img", picBefore);
    waitKey();
    
    int i = 100;
    Mat img = picBefore.clone();
    clock_t start_t, end_t;
    int num = i;
    start_t = clock();
    while (i > 0) {
        end_t = clock();
        if (end_t - start_t > 10000) {
            --i;
            for (size_t row = 0; row < picBefore.rows; ++row) {
                for (size_t col = 0; col < picBefore.cols; ++col) {
                    Scalar color1 = picBefore.at<Vec3b>(col,row);
                    Scalar color2 = picAfter.at<Vec3b>(col,row);
                    img.at<Vec3b>(col,row) = Vec3b
                    (color1(0)*i/num+color2(0)*(num-i)/num,
                     color1(1)*i/num+color2(1)*(num-i)/num,
                     color1(2)*i/num+color2(2)*(num-i)/num);
                }
            }
            imshow("img", img);
            waitKey(1);
            start_t = end_t;
        }
    }
    cout << "press Enter to exit" << endl;
    waitKey();
    return 0;
}
