// /*
//  * @Description: 
//  */
// #include "../../../include/mapping/loop_closing/loop_closing_flow.hpp"
// #include "robot_localization/mapping/"
// #include "glog/logging.h"
// #include "../../../include/global_path_defination/global_path.h"
// namespace robot_localization {
// LoopClosingFlow::LoopClosingFlow(std::shared_ptr<rclcpp::Node> &node_) 
// {
//     // subscriber:
//     key_scan_sub_ptr_ = std::make_shared<CloudSubscriber>(node_, "/key_scan", 100000);
//     key_frame_sub_ptr_ = std::make_shared<KeyFrameSubscriber>(node_, "/key_frame", 100000);
//     key_gnss_sub_ptr_ = std::make_shared<KeyFrameSubscriber>(node_, "/key_gnss", 100000);
//     // publisher
//     loop_pose_pub_ptr_ = std::make_shared<LoopPosePublisher>(node_, "/loop_pose", "/map", 100);
//     // loop closing
//     loop_closing_ptr_ = std::make_shared<LoopClosing>();
// }

// bool LoopClosingFlow::Run() 
// {
//     if (!ReadData())
//         return false;

//     while(HasData()) 
//     {
//         if (!ValidData())
//             continue;
        
//         loop_closing_ptr_->Update(current_key_scan_, current_key_frame_, current_key_gnss_);
        
//         PublishData();
//     }

//     return true;
// }

// bool LoopClosingFlow::Save(void) 
// {
//     return loop_closing_ptr_->Save();
// }

// bool LoopClosingFlow::ReadData() 
// {
//     key_scan_sub_ptr_->ParseData(key_scan_buff_);
//     key_frame_sub_ptr_->ParseData(key_frame_buff_);
//     key_gnss_sub_ptr_->ParseData(key_gnss_buff_);

//     return true;
// }

// bool LoopClosingFlow::HasData() 
// {
//     if( key_scan_buff_.size()  == 0 ||
//         key_frame_buff_.size() == 0 ||
//         key_gnss_buff_.size()  == 0
//       ) 
//     {
//         return false;
//     }

//     return true;
// }

// bool LoopClosingFlow::ValidData() 
// {
//     current_key_scan_ = key_scan_buff_.front();
//     current_key_frame_ = key_frame_buff_.front();
//     current_key_gnss_ = key_gnss_buff_.front();

//     double diff_gnss_time = current_key_frame_.time - current_key_gnss_.time;

//     if (diff_gnss_time < -0.05) 
//     {
//         key_frame_buff_.pop_front();
//         return false;
//     }

//     if (diff_gnss_time > 0.05) 
//     {
//         key_gnss_buff_.pop_front();
//         return false;
//     }

//     key_scan_buff_.pop_front();
//     key_frame_buff_.pop_front();
//     key_gnss_buff_.pop_front();

//     return true;
// }

// bool LoopClosingFlow::PublishData() 
// {
//     if (loop_closing_ptr_->HasNewLoopPose()) 
//         loop_pose_pub_ptr_->Publish(loop_closing_ptr_->GetCurrentLoopPose());

//     return true;
// }
// }