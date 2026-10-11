
#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include <ctime>
#include <memory>

class TimePrinter : public rclcpp::Node {
public:
    TimePrinter() : Node("time_printer") {
        timer = create_wall_timer(std::chrono::seconds(5), [this]() {
            std::time_t now = std::time(nullptr);
            char time_str[32];
            std::strftime(time_str, sizeof(time_str), "%d.%m.%Y %H:%M:%S", std::localtime(&now));
            RCLCPP_INFO(get_logger(), "Текущее время: %s", time_str);
        });
    }

private:
    rclcpp::TimerBase::SharedPtr timer;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TimePrinter>());
    rclcpp::shutdown();
    return 0;
}

