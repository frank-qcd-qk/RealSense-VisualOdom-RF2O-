#include<ros/ros.h> 
#include<std_msgs/Float64.h>
#include<tf/tf.h>
#include<geometry_msgs/Twist.h>
#include<geometry_msgs/Pose.h>
#include<nav_msgs/Odometry.h>
#include<fstream>

std::ofstream fused_logger_file("/home/frank/rsodomData/fused_odom_data.csv", std::ios::out | std::ios::binary);
std::ofstream top_logger_file("/home/frank/rsodomData/top_odom_data.csv", std::ios::out | std::ios::binary);
std::ofstream center_logger_file("/home/frank/rsodomData/center_odom_data.csv", std::ios::out | std::ios::binary);
std::ofstream bottom_logger_file("/home/frank/rsodomData/bottom_odom_data.csv", std::ios::out | std::ios::binary);
std::ofstream real_logger_file("/home/frank/rsodomData/real_odom_data.csv", std::ios::out | std::ios::binary);

void ekf_odom_writer_fused(const nav_msgs::Odometry::ConstPtr& message_holder) 
{
    tf::Quaternion q(message_holder->pose.pose.orientation.x, message_holder->pose.pose.orientation.y, message_holder->pose.pose.orientation.z, message_holder->pose.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    
    float x_pos = message_holder->pose.pose.position.x;
    float y_pos = message_holder->pose.pose.position.y;

    yaw = yaw*180.0/3.1415926;
    
    ROS_INFO("Received x_pos is: %f",x_pos); 
    ROS_INFO("Received y_pos is: %f",y_pos); 
    ROS_INFO("Recieved Yaw is: %d",yaw);
    fused_logger_file<<x_pos<<","<<y_pos<<","<<yaw<<"\n";
}

void ekf_odom_writer_top(const nav_msgs::Odometry::ConstPtr& message_holder) 
{
    tf::Quaternion q(message_holder->pose.pose.orientation.x, message_holder->pose.pose.orientation.y, message_holder->pose.pose.orientation.z, message_holder->pose.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    
    float x_pos = message_holder->pose.pose.position.x;
    float y_pos = message_holder->pose.pose.position.y;

    yaw = yaw*180.0/3.1415926;

    ROS_INFO("Received x_pos is: %f",x_pos); 
    ROS_INFO("Received y_pos is: %f",y_pos); 
    ROS_INFO("Recieved Yaw is: %d",yaw);
    top_logger_file<<x_pos<<","<<y_pos<<","<<yaw<<"\n";
}

void ekf_odom_writer_center(const nav_msgs::Odometry::ConstPtr& message_holder) 
{
    tf::Quaternion q(message_holder->pose.pose.orientation.x, message_holder->pose.pose.orientation.y, message_holder->pose.pose.orientation.z, message_holder->pose.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    
    float x_pos = message_holder->pose.pose.position.x;
    float y_pos = message_holder->pose.pose.position.y;
    
    yaw = yaw*180.0/3.1415926;

    ROS_INFO("Received x_pos is: %f",x_pos); 
    ROS_INFO("Received y_pos is: %f",y_pos); 
    ROS_INFO("Recieved Yaw is: %d",yaw);
    center_logger_file<<x_pos<<","<<y_pos<<","<<yaw<<"\n";
}

void ekf_odom_writer_bottom(const nav_msgs::Odometry::ConstPtr& message_holder) 
{
    tf::Quaternion q(message_holder->pose.pose.orientation.x, message_holder->pose.pose.orientation.y, message_holder->pose.pose.orientation.z, message_holder->pose.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    
    float x_pos = message_holder->pose.pose.position.x;
    float y_pos = message_holder->pose.pose.position.y;

    yaw = yaw*180.0/3.1415926;


    ROS_INFO("Received x_pos is: %f",x_pos); 
    ROS_INFO("Received y_pos is: %f",y_pos); 
    ROS_INFO("Recieved Yaw is: %d",yaw);
    bottom_logger_file<<x_pos<<","<<y_pos<<","<<yaw<<"\n";
}

void ekf_odom_writer_real(const nav_msgs::Odometry::ConstPtr& message_holder) 
{
    tf::Quaternion q(message_holder->pose.pose.orientation.x, message_holder->pose.pose.orientation.y, message_holder->pose.pose.orientation.z, message_holder->pose.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    
    float x_pos = message_holder->pose.pose.position.x;
    float y_pos = message_holder->pose.pose.position.y;

    yaw = yaw*180.0/3.1415926;


    ROS_INFO("Received x_pos is: %f",x_pos); 
    ROS_INFO("Received y_pos is: %f",y_pos); 
    ROS_INFO("Recieved Yaw is: %d",yaw);
    real_logger_file<<x_pos<<","<<y_pos<<","<<yaw<<"\n";
}

int main(int argc, char **argv) 
{ 
  ros::init(argc,argv,"minimal_subscriber"); 
  ros::NodeHandle n;  
    fused_logger_file<<"x_pos,y_pos,yaw\n";
    top_logger_file<<"x_pos,y_pos,yaw\n";
    center_logger_file<<"x_pos,y_pos,yaw\n";
    bottom_logger_file<<"x_pos,y_pos,yaw\n";
    ros::Subscriber ekf_odom_subscriber_fused= n.subscribe("odometry_rf2o/FUSED",1,ekf_odom_writer_fused); 
    ros::Subscriber ekf_odom_subscriber_top= n.subscribe("odometry_rf2o/top",1,ekf_odom_writer_top); 
    ros::Subscriber ekf_odom_subscriber_center= n.subscribe("odometry_rf2o/center",1,ekf_odom_writer_center); 
    ros::Subscriber ekf_odom_subscriber_bottom= n.subscribe("odometry_rf2o/bottom",1,ekf_odom_writer_bottom); 
    ros::Subscriber ekf_odom_subscriber_real= n.subscribe("odometry_rf2o/real_laser",1,ekf_odom_writer_real); 

  ros::spin(); 
  return 0; 
} 