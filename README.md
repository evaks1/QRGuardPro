
\# QRGuardPro

**\*\*QRGuardPro\*\*** is a robust C++ application designed to scan and generate QR codes with integrated safety evaluations using the Google Safe Browsing API. Leveraging powerful libraries like Qt6 for the user interface, OpenCV for image processing, libqrencode for QR code generation, and CURL for network operations, QRGuardPro offers a seamless and secure experience for handling QR codes.

\## Table of Contents

\- \[Features\](#features)

\- \[Prerequisites\](#prerequisites)

\- \[Installation\](#installation)

  - \[Using the Setup Script (macOS)\](#using-the-setup-script-macos)

  - \[Manual Installation\](#manual-installation)

\- \[Building the Project\](#building-the-project)

\- \[Running the Application\](#running-the-application)

\- \[Usage\](#usage)

\- \[Environment Variables\](#environment-variables)

\- \[Troubleshooting\](#troubleshooting)


\- \[License\](#license)

\## Features

\- **\*\*QR Code Scanning:\*\*** Select and scan QR code images to decode embedded data.

\- **\*\*QR Code Generation:\*\*** Input data to generate custom QR codes.

\- **\*\*Safety Evaluation:\*\*** Automatically evaluates the safety of scanned URLs using the Google Safe Browsing API.

\- **\*\*User-Friendly Interface:\*\*** Intuitive GUI built with Qt6 for seamless interactions.

\- **\*\*Cross-Platform Support:\*\*** Compatible with macOS, Linux, and Windows (with appropriate modifications).

\## Prerequisites

Before setting up **\*\*QRGuardPro\*\***, ensure you have the following installed on your system:

\- **\*\*C++ Compiler:\*\*** Compatible with C++17 (e.g., AppleClang on macOS, GCC on Linux, MSVC on Windows)

\- **\*\*CMake:\*\*** Version 3.14 or higher

\- **\*\*Git:\*\*** For cloning the repository

\- **\*\*Homebrew (macOS Only):\*\*** Package manager for installing dependencies

\- **\*\*Qt6:\*\*** For the user interface

\- **\*\*OpenCV:\*\*** For image processing

\- **\*\*libqrencode:\*\*** For QR code generation

\- **\*\*CURL:\*\*** For network operations

\## Installation

\### Using the Setup Script (macOS)

For macOS users, a setup script is provided to automate the installation of necessary dependencies using Homebrew.

1\. **\*\*Clone the Repository:\*\***

   \`\`\`bash

   git clone https://github.com/yourusername/QRGuardPro.git

   cd QRGuardPro

2.**Make the Setup Script Executable:**

chmod +x setup.sh

3.**Run the Setup Script:**

./setup.sh

_This script will install the required dependencies and set up the project for building._

**Manual Installation**

If you prefer to install dependencies manually or are using a different operating system, follow these steps:

1.**Clone the Repository:**

git clone https://github.com/yourusername/QRGuardPro.git

cd QRGuardPro

2.**Install Dependencies:**

•**macOS (Using Homebrew):**

brew install qt@6

brew install opencv

brew install qrencode

brew install curl

•**Ubuntu/Linux:**

sudo apt update

sudo apt install build-essential cmake git libqt6-dev libopencv-dev libqrencode-dev libcurl4-openssl-dev

•**Windows:**

•**Qt6:** Download and install from the [official website](https://www.qt.io/download).

•**OpenCV:** Download and install from the [official website](https://opencv.org/releases/).

•**libqrencode & CURL:** Consider using [vcpkg](https://github.com/microsoft/vcpkg) to install these libraries.

3.**Set Environment Variables (If Necessary):**

Ensure that the installation paths of Qt6 and other libraries are discoverable by CMake. You may need to set the CMAKE\_PREFIX\_PATH.

•**macOS/Linux:**

export CMAKE\_PREFIX\_PATH="/opt/homebrew/opt/qt@6/lib/cmake:$CMAKE\_PREFIX\_PATH"

_You can add the above line to your shell’s configuration file (e.g., .bashrc, .zshrc) to make it persistent._

•**Windows:**

Add the Qt6 and other library paths to your system’s PATH environment variable or configure them within CMake.

**Building the Project**

1.**Navigate to the Project Directory:**

cd QRGuardPro

2.**Create a Build Directory:**

It’s good practice to build your project in a separate directory to keep the source tree clean.

mkdir build

cd build

3.**Configure the Project with CMake:**

cmake ..

_CMake will detect all dependencies and configure the build accordingly._

**Optional:** If Qt6 is installed in a non-standard location, specify the CMAKE\_PREFIX\_PATH:

cmake -DCMAKE\_PREFIX\_PATH=/opt/homebrew/opt/qt@6/lib/cmake ..

4.**Build the Project:**

make

_This will compile the source code and generate the QRGuardPro executable._

**Note for Windows Users:**

Use the appropriate build tool, such as Visual Studio, to build the project. You can generate Visual Studio project files with CMake:

cmake -G "Visual Studio 16 2019" ..

**Running the Application**

After a successful build, you can run the application as follows:

•**macOS/Linux:**

./QRGuardPro

•**Windows:**

Double-click the QRGuardPro.exe file in the build directory or run it via the command prompt.

**Ensure that your environment variables (like** GOOGLE\_SAFE\_BROWSING\_API\_KEY**) are set before running the application.**

**Usage**

1.**Scan QR Code:**

•Click on the “Select Image to Scan” button.

•Choose an image file containing a QR code.

•The application will display the scanned data and evaluate its safety.

2.**Generate QR Code:**

•Enter the desired data in the input field.

•Click on the “Generate QR Code” button.

•The generated QR code will be displayed.

•Save the QR code image using the provided dialog.

**Environment Variables**

**QRGuardPro** relies on the GOOGLE\_SAFE\_BROWSING\_API\_KEY environment variable to evaluate the safety of scanned URLs.

1.**Obtain an API Key:**

Follow the [Google Safe Browsing API documentation](https://developers.google.com/safe-browsing/v4/get-started) to obtain an API key.

2.**Set the Environment Variable:**

•**macOS/Linux:**

export GOOGLE\_SAFE\_BROWSING\_API\_KEY="YOUR\_API\_KEY\_HERE"

_To make this persistent across sessions, add the above line to your shell’s configuration file (e.g., .bashrc, .zshrc)._

•**Windows:**

•Open the **Environment Variables** settings.

•Create a new **User** or **System** variable named GOOGLE\_SAFE\_BROWSING\_API\_KEY.

•Set its value to your API key.

**Troubleshooting**

**Common Issues**

1.**Undefined Symbols (vtable errors):**

•**Cause:** Missing Q\_OBJECT macro or MOC not processing the class.

•**Solution:**

•Ensure the Q\_OBJECT macro is present in your class definition.

•Verify that CMake’s AUTOMOC is enabled.

•Perform a clean build by deleting the build directory and rebuilding.

2.**CMake Cannot Find Qt6:**

•**Cause:** Incorrect CMAKE\_PREFIX\_PATH or Qt6 not installed.

•**Solution:**

•Verify that Qt6 is installed.

•Ensure CMAKE\_PREFIX\_PATH points to Qt6’s CMake directory.

•Example for macOS:

export CMAKE\_PREFIX\_PATH="/opt/homebrew/opt/qt@6/lib/cmake"

3.**Missing Qt Headers:**

•**Cause:** Not including necessary Qt headers in your source files.

•**Solution:**

•Ensure all used Qt classes have their corresponding headers included.

•Example:

#include

#include

#include

#include

#include

#include

#include

#include

4.**Linker Errors Related to CURL or OpenCV:**

•**Cause:** Libraries not found or mismatched architectures.

•**Solution:**

•Ensure libraries are installed and paths are correctly set.

•Verify that all libraries target the same architecture as your project (arm64).

**Debugging Tips**

•**Enable Verbose Make Output:**

make VERBOSE=1

_This provides detailed information about the build process, helping identify where errors occur._

•**Check CMake Cache Variables:**

cmake -LAH | grep Qt

cmake -LAH | grep CURL

cmake -LAH | grep OpenCV

_Ensure that CMake has correctly found all dependencies._

•**Use Qt Creator:**

Qt Creator is an IDE tailored for Qt projects, providing integrated tools for building and debugging.

1.**Install Qt Creator (if not already installed):**

brew install --cask qt-creator

2.**Open the Project in Qt Creator:**

•Launch Qt Creator.

•Open the CMakeLists.txt file from your project directory.

•Configure and build the project using the IDE’s interface.

**License**

This project is licensed under the [MIT License](LICENSE).

