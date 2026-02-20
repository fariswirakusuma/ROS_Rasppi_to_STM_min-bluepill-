#include <Arduino.h>
#include "micro_ros_arduino.h"
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <std_msgs/msg/int32.h>


rcl_publisher_t publisher;
std_msgs__msg__Int32 msg;
rclc_executor_t executor;
rcl_node_t node;
rcl_allocator_t allocator;
rclc_support_t support;

void setup() {
  Serial.begin(115200);
  set_microros_serial_transports(Serial);

  allocator = rcl_get_default_allocator();
  rclc_support_init(&support, 0, NULL, &allocator);

  rclc_node_init_default(&node, "stm_node", "", &support);

  rclc_publisher_init_default(
    &publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
    "stm_counter"
  );

  rclc_executor_init(&executor, &support.context, 1, &allocator);
}

void loop() {
  static int count = 0;
  msg.data = count++;
  rcl_publish(&publisher, &msg, NULL);
  delay(1000);
}