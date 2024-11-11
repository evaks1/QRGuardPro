#!/bin/bash

# setup.sh
# This script installs all necessary dependencies for QRGuardPro on macOS using Homebrew.

# Exit immediately if a command exits with a non-zero status.
set -e

# Function to print messages in green
function print_success {
    echo -e "\033[0;32m$1\033[0m"
}

# Function to print messages in yellow
function print_warning {
    echo -e "\033[1;33m$1\033[0m"
}

# Function to print messages in red
function print_error {
    echo -e "\033[0;31m$1\033[0m"
}

echo "==============================="
echo "Welcome to QRGuardPro Setup Script"
echo "==============================="

# Check if Homebrew is installed
if ! command -v brew &> /dev/null
then
    print_error "Homebrew is not installed. Please install Homebrew first by following the instructions at https://brew.sh/ and then re-run this script."
    exit 1
fi

print_success "Homebrew is installed."

# Update Homebrew
print_success "Updating Homebrew..."
brew update

# Upgrade any already-installed formulae
print_success "Upgrading existing Homebrew packages..."
brew upgrade

# Install Qt6
print_success "Installing Qt6..."
brew install qt@6

# Install OpenCV
print_success "Installing OpenCV..."
brew install opencv

# Install libqrencode
print_success "Installing libqrencode..."
brew install qrencode

# Install CURL
print_success "Installing CURL..."
brew install curl

# Link Qt6 (Force linking if necessary)
if brew list qt@6 &> /dev/null
then
    print_success "Linking Qt6..."
    brew link qt@6 --force --overwrite
else
    print_warning "Qt6 is already linked."
fi

# Verify installations
print_success "Verifying installations..."

# Check Qt6
if brew list qt@6 &> /dev/null
then
    print_success "Qt6 installed successfully."
else
    print_error "Qt6 installation failed."
    exit 1
fi

# Check OpenCV
if brew list opencv &> /dev/null
then
    print_success "OpenCV installed successfully."
else
    print_error "OpenCV installation failed."
    exit 1
fi

# Check libqrencode
if brew list qrencode &> /dev/null
then
    print_success "libqrencode installed successfully."
else
    print_error "libqrencode installation failed."
    exit 1
fi

# Check CURL
if brew list curl &> /dev/null
then
    print_success "CURL installed successfully."
else
    print_error "CURL installation failed."
    exit 1
fi

# Set CMAKE_PREFIX_PATH for the current session
export CMAKE_PREFIX_PATH="/opt/homebrew/opt/qt@6/lib/cmake:$CMAKE_PREFIX_PATH"
print_success "Set CMAKE_PREFIX_PATH for the current session."

# Inform the user to add CMAKE_PREFIX_PATH to their shell configuration for persistence
print_warning "To make CMAKE_PREFIX_PATH persistent across sessions, add the following line to your shell configuration file (e.g., ~/.zshrc or ~/.bash_profile):"
echo "export CMAKE_PREFIX_PATH=\"/opt/homebrew/opt/qt@6/lib/cmake:\$CMAKE_PREFIX_PATH\""

# Prompt the user to set the GOOGLE_SAFE_BROWSING_API_KEY environment variable
echo
print_warning "Please ensure you have set the GOOGLE_SAFE_BROWSING_API_KEY environment variable."
echo "You can set it temporarily for the current session using:"
echo "export GOOGLE_SAFE_BROWSING_API_KEY=\"YOUR_API_KEY_HERE\""
echo "To make it persistent, add the above line to your shell configuration file (e.g., ~/.zshrc or ~/.bash_profile)."

# Optional: Install additional recommended tools
read -p "Would you like to install additional recommended tools (e.g., Qt Creator IDE)? [y/N]: " install_tools

if [[ "$install_tools" =~ ^([yY][eE][sS]|[yY])$ ]]
then
    print_success "Installing Qt Creator..."
    brew install --cask qt-creator
    print_success "Qt Creator installed successfully."
else
    print_warning "Skipping installation of additional tools."
fi

echo
print_success "==============================="
print_success "QRGuardPro Setup Completed Successfully!"
print_success "==============================="

echo
echo "Next Steps:"
echo "1. Ensure that the CMAKE_PREFIX_PATH is set in your shell configuration file to enable CMake to find Qt6:"
echo "   export CMAKE_PREFIX_PATH=\"/opt/homebrew/opt/qt@6/lib/cmake:\$CMAKE_PREFIX_PATH\""
echo "2. Set the GOOGLE_SAFE_BROWSING_API_KEY environment variable:"
echo "   export GOOGLE_SAFE_BROWSING_API_KEY=\"YOUR_API_KEY_HERE\""
echo "3. Clone the QRGuardPro repository and build the project:"
echo "   git clone https://github.com/yourusername/QRGuardPro.git"
echo "   cd QRGuardPro"
echo "   mkdir build && cd build"
echo "   cmake .."
echo "   make"
echo "4. Run the application:"
echo "   ./QRGuardPro"
echo
print_success "Happy Coding with QRGuardPro!"
