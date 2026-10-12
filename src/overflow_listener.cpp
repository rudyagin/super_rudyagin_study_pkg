#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <memory>

class OverflowListener : public rclcpp::Node {
public:
    OverflowListener() : Node("overflow_listener") {
        subscription = create_subscription<std_msgs::msg::Int32>("overflow", 10,
            [this](std_msgs::msg::Int32::SharedPtr msg) {
                RCLCPP_WARN(get_logger(), "Overflow! Received: %d", msg->data);
            });
    }
private:
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OverflowListener>());
    rclcpp::shutdown();
    return 0;
}
