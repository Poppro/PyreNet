# PyreNet
## About
### Intended Use
In short, this is a C++ neural network static library developed as a simple, elegant, multi-purpose solution.

To be a bit more elaborate, this library offers a simple interface for home-cooked reinforcement based deep learning projects. It is optimized for running in a multi-threaded environment, seeking to offer performance and simple, essential, features without the complexity endured from larger-scale libraries. This library does not currently support back propagation.

### Thread Safety
The library is designed to be fully thread-safe and can be used in multi-threaded enviroments.

## Quick Start

### Installation

For a pre-built library file, check out our [latest release](https://github.com/Poppro/PyreNet/releases/latest).
No additional dependencies are required.

### Example Usage

```c++
#include "PyreNet.h"

int main() {
  // Define middle and output layers
  std::vector<PyreNet::LayerDefinition> layerDefs;
  layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::relu);  // Middle (50 nodes)
  layerDefs.emplace_back(50, PyreNet::LayerDefinition::activationType::sigmoid);  // Middle (50 nodes)
  layerDefs.emplace_back(5, PyreNet::LayerDefinition::activationType::relu);  // Output (5 nodes)

  // Initialize the network
  PyreNet::NeuralNet nn(5, layerDefs);  // Defines the network to have an input size of 5
  nn.mutate_guassian(0, 1);  // Mutates network weights from a gaussian sample with mean 0, standard deviation 1

  // Run a prediction on an input vector
  std::vector<double> predictions = nn.predict(std::vector<double>{0, 1, 2, 3, 4});
}
```

## Features

### Activations

| Activation Type          |    Identifier    |
| ------------- | ------------- |
| ReLU          |   LayerDefinition::relu   |
| Linear          |   LayerDefinition::linear   |
| Hyperbolic Tangent          |   LayerDefinition::tanh   |
| Sigmoid          |   LayerDefinition::sigmoid   |
| Step          |   LayerDefinition::step   |

### Serialization
For convenience, all networks can easily be serialized and deserialized.
```c++
PyreNet::NeuralNet nn(5, layerDefs)

ofstream ofs("output.txt");
ofs << nn;

ifstream ifs("output.txt");
ifs >> nn;
```

### Mutations
#### Gaussian
```c++
mutate_gaussian(mean, std, OptionalInt(layerIndex));
```
Mutates the weights via a gaussian distribution.

If the layerIndex field is specified, only that layer will be mutated.
Indexing starts from 0 at the first set of weights.

#### Uniform
```c++
mutate_uniform(lower_bound, upper_bound, OptionalInt(layerIndex));
```

Mutates the weights uniformly by a modifier in the range [lower_bound, upper_bound].


## Contributing

Feel free to make a pull request if you have any useful features or bug fixes.
For inquiries, contact harloff@umich.edu.

## Authors

* **Hunter Harloff** - *Lead Developer* - [Poppro](https://github.com/Poppro)

## License

This project is licensed under the MIT License
