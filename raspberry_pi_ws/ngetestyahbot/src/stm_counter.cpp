#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class StmCounterNode : public rclcpp::Node
{
public:
  StmCounterNode() : Node("stm_counter_listener")
  {
    sub_ = this->create_subscription<std_msgs::msg::Int32>(
      "stm_counter",
      10,
      std::bind(&StmCounterNode::callback, this, std::placeholders::_1)
    );

    RCLCPP_INFO(this->get_logger(), "STM counter listener started");
  }

private:
  void callback(const std_msgs::msg::Int32::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "Received from STM: %d", msg->data);
  }

  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<StmCounterNode>());
  rclcpp::shutdown();
  return 0;
}
