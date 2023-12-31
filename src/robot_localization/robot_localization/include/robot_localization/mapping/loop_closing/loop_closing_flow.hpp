// /*
//  * @Description: 
//  */
// #ifndef MAPPING_LOOP_CLOSING_LOOP_CLOSING_FLOW_HPP_
// #define MAPPING_LOOP_CLOSING_LOOP_CLOSING_FLOW_HPP_

// #include <deque>
// #include "rclcpp/rclcpp.hpp"
// // subscriber
// #include "../../subscriber/cloud_subscriber.hpp"
// #include "../../subscriber/key_frame_subscriber.hpp"
// // publisher
// #include "../../publisher/loop_pose_publisher.hpp"
// // loop closing
// #include "loop_closing.hpp"

// namespace robot_localization {
// class LoopClosingFlow 
// {
//   public:
//     LoopClosingFlow(std::shared_ptr<rclcpp::Node> &node_);

//     bool Run();
//     bool Save();
    
//   private:
//     bool ReadData();
//     bool HasData();
//     bool ValidData();
//     bool PublishData();

//   private:
//     // subscriber
//     std::shared_ptr<CloudSubscriber> key_scan_sub_ptr_;
//     std::shared_ptr<KeyFrameSubscriber> key_frame_sub_ptr_;
//     std::shared_ptr<KeyFrameSubscriber> key_gnss_sub_ptr_;
//     // publisher
//     std::shared_ptr<LoopPosePublisher> loop_pose_pub_ptr_;
//     // loop closing
//     std::shared_ptr<LoopClosing> loop_closing_ptr_;

//     std::deque<CloudData> key_scan_buff_;
//     std::deque<KeyFrame> key_frame_buff_;
//     std::deque<KeyFrame> key_gnss_buff_;

//     CloudData current_key_scan_;
//     KeyFrame current_key_frame_;
//     KeyFrame current_key_gnss_;
// };
// }

// #endif