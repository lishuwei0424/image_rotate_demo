#include <sstream>
#include "ros/ros.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <string>
#include <opencv2/opencv.hpp>  


using namespace std;
using namespace cv;
int main(int argc, char **argv)
{
  ros::init(argc, argv, "image_publisher_node"); //ROS节点初始化
  ros::NodeHandle nh;  //创建节点句柄

  cout<<1<<endl;

  image_transport::ImageTransport it(nh);
  //创建一个Publisher，发布名为chatter的topic，消息类型为std_msgs::String
  image_transport::Publisher pub = it.advertise("image_raw", 1);

  ros::Rate loop_rate(5);

   string pattern = "/home/lishuwei/catkin_ws/src/image_rotate_demo/image_dir/*.bmp";
	vector<String> image_name;
	glob(pattern, image_name, true);
	size_t count = image_name.size();

  int i=0;
  cv::Mat image;
  while (nh.ok()) {
    if(i>=count){
         cout<<"deal endl:"<<count<<endl;
        return 0;
    }

    cout<<image_name[i]<<endl;
    image = imread(image_name[i]);
    cv::imshow("image_raw",image);
    cv::waitKey(30);
    i++;

    sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
