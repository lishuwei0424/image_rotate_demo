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
<iframe src="//player.bilibili.com/player.html?aid=926428646&bvid=BV1wT4y1j7sR&cid=213677417&page=1" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>




