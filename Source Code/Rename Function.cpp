std::string generate_new_filename(std::string original_filename, float bpm) {
  std::string extension = original_filename.substr(original_filename.find_last_of(".") + 1);
  std::string basename = original_filename.substr(0, original_filename.find_last_of("."));
  std::stringstream ss;
  ss << basename << "_" << std::fixed << std::setprecision(2) << bpm << "." << extension;
  return ss.str();
}
