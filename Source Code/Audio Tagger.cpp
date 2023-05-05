#include <essentia/algorithmfactory.h>
#include <essentia/pool.h>

int main(int argc, char* argv[]) {
  // Load the audio file using Essentia's standard MonoLoader algorithm
  std::string filename = "path/to/audio/file.mp3";
  essentia::standard::MonoLoader loader;
  loader.configure(filename);
  essentia::RealVector audio;
  loader(audio);

  // Extract the BPM value using Essentia's RhythmExtractor2013 algorithm
  essentia::Pool pool;
  essentia::standard::RhythmExtractor2013 rhythm_extractor;
  rhythm_extractor(audio, pool);

  float bpm = pool.value<float>("bpm");
  std::cout << "BPM value: " << bpm << std::endl;

  return 0;
}

std::string generate_new_filename(std::string original_filename, float bpm) {
  std::string extension = original_filename.substr(original_filename.find_last_of(".") + 1);
  std::string basename = original_filename.substr(0, original_filename.find_last_of("."));
  std::stringstream ss;
  ss << basename << "_" << std::fixed << std::setprecision(2) << bpm << "." << extension;
  return ss.str();
}
