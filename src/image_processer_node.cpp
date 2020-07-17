#include "ros/ros.h"  
#include "image_transport/image_transport.h"  
#include "cv_bridge/cv_bridge.h"  
#include "sensor_msgs/image_encodings.h"  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <iostream>  
      
namespace enc = sensor_msgs::image_encodings;   
      
class ImageConvertor  
{  
    ros::NodeHandle nh_;  
    image_transport::ImageTransport it_;  
    image_transport::Subscriber image_sub_;  
    image_transport::Publisher image_pub_;  

    int count;
      
    public:  
    ImageConvertor():it_(nh_){  
        //发布主题image_rotate  
        image_pub_ = it_.advertise("image_rotate", 1); 
        
        //订阅主题image_raw 
        image_sub_ = it_.subscribe("image_raw", 1, &ImageConvertor::ImageCb, this);  
        
    }  
  
    ~ImageConvertor()  
    {  
        
    }  
  
    void ImageCb(const sensor_msgs::ImageConstPtr& msg)  
    {  
        cv_bridge::CvImagePtr cv_ptr;  
  
        try  
        {  
            /*转化成CVImage*/  
            cv_ptr = cv_bridge::toCvCopy(msg, enc::BGR8);  
            //cv::imshow("image_raw",cv_ptr->image);
            //cv::waitKey(30);
        }  
        catch (cv_bridge::Exception& e)  
        {  
            ROS_ERROR("cv_bridge exception is %s", e.what());  
            return;  
        }  
        
        //将图片顺时针旋转90°后
        cv::Mat img;  
        cv::transpose(cv_ptr->image, img);
        cv::flip(img, img, 1);
  
        cv_ptr->image=img;
        image_pub_.publish(cv_ptr->toImageMsg());  

        cv::cvtColor(img, img, CV_RGB2GRAY);  
        cv::imshow("image_rotate",img);
        cv::waitKey(3); 
        count++;
        std::cout<<"deal image:"<<count<<std::endl;
    }  
};  
      
int main(int argc, char** argv)  
{  
    ros::init(argc, argv, "image_node_b");  
    ImageConvertor ic;  
    ros::spin();  
      
    return 0;  
}
