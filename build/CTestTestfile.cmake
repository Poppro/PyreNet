# CMake generated Testfile for 
# Source directory: /Users/skhatib/Documents/Coding Projects/PyreNet
# Build directory: /Users/skhatib/Documents/Coding Projects/PyreNet/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(PyreNetTest "tst/Test.cpp" "src/PyreNet.h" "src/NeuralNet.cpp" "src/NeuralNet.h" "src/Layer.cpp" "src/Layer.h" "src/LayerDefinition.cpp" "src/LayerDefinition.h" "src/Perceptron.cpp" "src/Perceptron.h" "src/activations/Activation.cpp" "src/activations/Activation.h" "src/activations/ActivationFactory.cpp" "src/activations/ActivationFactory.h" "src/activations/Linear.cpp" "src/activations/Linear.h" "src/activations/Relu.cpp" "src/activations/Relu.h" "src/activations/Sigmoid.cpp" "src/activations/Sigmoid.h" "src/activations/Step.cpp" "src/activations/Step.h" "src/activations/Tanh.cpp" "src/activations/Tanh.h" "src/exceptions/InvalidInputSize.cpp" "src/exceptions/InvalidInputSize.h" "src/exceptions/InvalidLayer.cpp" "src/exceptions/InvalidLayer.h" "src/random/RandomGenerator.cpp" "src/random/RandomGenerator.h" "src/thread/LayerThreadPool.cpp" "src/thread/LayerThreadPool.h")
set_tests_properties(PyreNetTest PROPERTIES  _BACKTRACE_TRIPLES "/Users/skhatib/Documents/Coding Projects/PyreNet/CMakeLists.txt;8;ADD_TEST;/Users/skhatib/Documents/Coding Projects/PyreNet/CMakeLists.txt;0;")
