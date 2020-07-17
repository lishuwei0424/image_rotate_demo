# image_rotate_demo
## subject description：
```
Using ROS to realize two ROS nodes. image_ Publisher node is responsible for transferring the file in image/dir,
publish, and then image_processor node is responsible for rotating the image 90 ° clockwise and then pushing it out.
```

## build  on ROS Kinetic From Source
```bash
mkdir -p  ~/caktin_ws/src  
cd ~/caktin_ws/src  
git clone  https://github.com/lishuwei0424/image_rotate_demo  
cd  ../  
catkin_make  
```    

## run From Command Line   
teminal 1.
```bash
roscore  
```

teminal 2. 
```bash
   source  ./devel/setup.bash  
   rosrun   image_rotate_demo   image_processer_node  
   roscore  
 ```

teminal 3.   
```bash
   source  ./devel/setup.bash  
   rosrun  image_rotate_demo  image_publisher_node  
   roscore  
```

## viedo for show  
[![Watch the video](https://github.com/lishuwei0424/image_rotate_demo/blob/master/viedo.bmp)](
https://www.bilibili.com/video/BV1wT4y1j7sR)

