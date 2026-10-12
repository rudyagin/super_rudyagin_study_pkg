#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <chrono>
#include <memory>

class EvenPublisher : public rclcpp::Node {
public:
    EvenPublisher() : Node("even_pub") {
        even_pub = create_publisher<std_msgs::msg::Int32>("even_numbers", 10);
        overflow_pub = create_publisher<std_msgs::msg::Int32>("overflow", 10);
        timer = create_wall_timer(std::chrono::milliseconds(100), [this]() {
            std_msgs::msg::Int32 msg;
            msg.data = number;
            even_pub->publish(msg);
            RCLCPP_INFO(get_logger(), "Number: %d", number);
            number += 2;
            if (number >= 100) {
                std_msgs::msg::Int32 overflow_msg;
                overflow_msg.data = number;
                overflow_pub->publish(overflow_msg);
                number = 0;
            }
        });
    }
private:
    int number = 0;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr even_pub;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr overflow_pub;
    rclcpp::TimerBase::SharedPtr timer;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<EvenPublisher>());
    rclcpp::shutdown();
    return 0;
}
