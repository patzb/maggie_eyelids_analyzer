#ifndef MAGGIE_EYELIDS_ANALYZER_H
#define MAGGIE_EYELIDS_ANALYZER_H

#include <ros/ros.h>
#include <diagnostic_aggregator/analyzer.h>
#include <diagnostic_aggregator/status_item.h>
#include <diagnostic_msgs/DiagnosticStatus.h>
#include <pluginlib/class_list_macros.h>
#include <string>

namespace diagnostic_aggregator {

class MaggieEyelidsAnalyzer : public Analyzer {
public:
  MaggieEyelidsAnalyzer();

  ~MaggieEyelidsAnalyzer();

  bool init(const std::string base_name, const ros::NodeHandle &n);

  bool match(const std::string name);

  bool analyze(const boost::shared_ptr<StatusItem> item);

  std::vector<boost::shared_ptr<diagnostic_msgs::DiagnosticStatus> > report();

  std::string getPath() const { return path_; }

  std::string getName() const { return nice_name_; }

private:
	
  std::string path_, nice_name_;

  boost::shared_ptr<StatusItem> eyelid_right_item_;
  boost::shared_ptr<StatusItem> eyelid_left_item_;

  bool has_initialized_, has_eye_right_data_, has_eye_left_data_;
};

}
#endif //MAGGIE_EYELIDS_ANALYZER_H
