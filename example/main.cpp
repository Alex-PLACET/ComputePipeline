#include <ComputePipeline/ComputePipeline.hpp>

#include "DecodeImageAction.hpp"
#include "DecompressAction.hpp"
#include "DeserializeJSONAction.hpp"
#include "LoadAction.hpp"

#include <iostream>

int main(int argc, char **argv) {
  ComputePipeline::ComputePipeline pipeline(LoadAction);
  pipeline.addAction(DecodeImageAction);
  pipeline.addAction(DecompressAction);
  pipeline.addAction(DeserializeJSONAction);
  try {
    pipeline.addAction(DeserializeJSONAction);
  } catch (const std::exception &e) {
    std::cout << "Catch an expected exception as we add an action which take as argument an already handled type: " << e.what() << std::endl;
  }
  std::cout << "Fetch file://test.zip: " << std::endl;
  const std::any test_1 = pipeline.compute("file://test.zip");
  std::cout << "Fetch http://test.png: " << std::endl;
  const std::any test_2 = pipeline.compute("http://test.png");
  std::cout << "Fetch bundle://test.json: " << std::endl;
  const std::any test_3 = pipeline.compute("bundle://test.json");
  try {
    pipeline.compute("ftp://test.avi");
  } catch (const std::exception &e) {
    std::cout << "Catch an expected exception as we try yo fetch with a ftp address: " << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
