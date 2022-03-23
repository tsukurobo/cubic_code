#include "ros/ros.h"
/* 送信内容
 * 
 */

#include "pwm/pwm.h"

ros::Publisher pub_mega;
ros::Subscriber sub_task;

int on_off = 0;
int freq = 50;
int duty = 50;

/*void all_stop();
void collect();
void publish_ard();
void get_order(const std_msgs::Int32& task_order);*/

int main(int argc, char **argv) {

	ros::init(argc, argv, "rack_talker");
	ros::NodeHandle nh;
	
	/*pub_ard = nh.advertise<std_msgs::Int32MultiArray>("rack_ard_order", 1);
	sub_task = nh.subscribe("rack_task_order", 1, get_order);
	
	nh.getParam("deg_ini1",deg_ini1);
	nh.getParam("deg_ini2",deg_ini2);
	nh.getParam("deg_pick1",deg_pick1);
	nh.getParam("deg_pick2",deg_pick2);
	nh.getParam("deg_load1",deg_load1);
	nh.getParam("deg_load2",deg_load2);

	ros::Rate loop_rate(100);

	while (ros::ok()) {
		ros::spinOnce();
		
		if (order == 0) { //停止

			all_stop();

		} else { //ラック回収

			collect();
		}

		publish_ard();

		loop_rate.sleep();

	}
    */
	return 0;
}

/*
void publish_ard() {
	ard_order.data.resize(3);
	ard_order.data[0] = deg_servo1;
	ard_order.data[1] = deg_servo2;
	ard_order.data[2] = solenoid;
	
	pub_ard.publish(ard_order);
}

void collect() {
	if (order == 1) { //アームをラックへ
		
		if (deg_servo1 != deg_pick1) {
			if (deg_servo1 < deg_pick1) deg_servo1 += 1;
			else deg_servo1 -= 1;
			solenoid = 1; //開いておく
		}

	} else if (order == 2) { //持ち手を差し込む

		if (deg_servo2 != deg_pick2) {
			if (deg_servo2 < deg_pick2) deg_servo2 += 1;
			else deg_servo2 -= 1;
			solenoid = 0; //緩めておく
		}

	} else if (order == 3) { //掴む

		solenoid = 2;

	} else if (order == 4) { //アームを射出機構へ

		if (deg_servo1 != deg_load1) {
			if (deg_servo1 < deg_load1) deg_servo1 += 1;
			else deg_servo1 -= 1;

		} else if (deg_servo2 != deg_load2) {
			if (deg_servo2 < deg_load2) deg_servo2 += 1;
			else deg_servo2 -= 1;
		}
	} else if (order == 5) { //離す

		solenoid = 1;
		all_stop();

	}
}

void all_stop() {
	order = 0;
	deg_servo1 = deg_ini1;
	deg_servo2 = deg_ini2;
	solenoid = 0;
}
*/