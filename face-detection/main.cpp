// source reference : ( Gursewak Singh, https://github.com/gursewaks056/FaceDetectionUsingCPP )

#include <iostream>
#include <stdlib.h>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

int main()
{

    //// loading xml 
    cv::CascadeClassifier faceDetection;
    string path_to_xml = "../data/haarcascades/haarcascade_frontalface_alt.xml";
    // string path_to_xml = "../data/haarcascades/haarcascade_frontalface_default.xml";

    // if file is not loaded properly
    if ( !faceDetection.load(path_to_xml) )
    {
        cout << "File is not loaded properly!\n";
        exit(0); // from stdlib.h
    }


    //// read image
    string path_to_img = "nirvana.jpeg";
    string save_path = "output.jpeg";
    cv::Mat img = cv::imread(path_to_img, 1);

    // if image is empty
    if ( img.empty() )
    {
        cout << "Image is not loaded properly" << endl;
        exit(0);
    }
    else
    {
        cout << "Image found" << endl;
        
        // process starts
        cout << "Processing ... " << endl;

        // create a vector of rectangles

        vector<cv::Rect> faces;

        // detection process
        // based on the image (img), and where to store it (faces)
        faceDetection.detectMultiScale( img, faces );


        for ( int i = 0 ; i < faces.size() ; i++ )
        {
            // first point
            cv::Point pt1( faces[i].x, faces[i].y );
            cv::Point pt2( faces[i].x + faces[i].height, faces[i].y + faces[i].width );

            // draw a rectangle
            // scalar is the color of the rectangle where we're drawing the face
            // 2 is thickness, 8 is line type, 
            cv::rectangle( img, pt1, pt2, cv::Scalar(0, 255, 0), 2, 8, 0 );
        }

        // saving the file
        cv::imwrite( save_path, img );

        cout << "Face detection complete" << endl;

    }


    return 0;

}