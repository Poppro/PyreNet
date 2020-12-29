# C++ neural network static library. Developed as a simple, elegant, multi-purpose solution.
This library offers a simple interface for home-cooked reinforcement based deep learning projects. It is optimized for running in a multi-threaded environment, seeking to offer performance and simple, essential, features without the complexity endured from larger-scale libraries. This library does not currently support back propagation.


# Quick Start

## Installation
The library should be built as a static c++ library. No additional dependencies are required.

## Example Usage

```
#include "PyreNet.h"

int main() {
  // Define middle and output layers
  std::vector<PyreNet::LayerDefinition> layerDefs;
  layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);  // Middle (50 nodes)
  layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::sigmoid);  // Middle (50 nodes)
  layerDefs.emplace_back(5, PyreNet::LayerDefinition::activationType::relu);  // Output (5 nodes)
  
  // Initialize the network
  PyreNet::NeuralNet nn(5, layerDefs);  // Defines the network to have an input size of 5
  nn.mutate(-1, 1);  // Mutates network weights to be between -1 and 1
  
  // Run a prediction on an input vector
  std::vector<double> predictions = nn.predict(std::vector<double>{0, 1, 2, 3, 4});
}
```
