# Dockerfile for bitmap2hex project
# Uses Ubuntu 26.04, installs wxWidgets 3.2 (or latest) and CMake

FROM ubuntu:26.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Install system dependencies
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        git \
        build-essential \
        cmake \
        wget \
        ca-certificates \
        libgtk-3-dev \
        libssl-dev \
        && rm -rf /var/lib/apt/lists/*

# Install wxWidgets 3.2 or latest
# Try to install wxWidgets 3.2 from apt, fall back to latest
RUN apt-get update && \
    (apt-get install -y --no-install-recommends libwxgtk3.2-dev 2>/dev/null && \
     echo "wxWidgets 3.2 installed successfully" || \
     (apt-get install -y --no-install-recommends libwxgtk3.0-dev 2>/dev/null && \
      echo "wxWidgets 3.0 installed as fallback" || \
      (apt-get install -y --no-install-recommends libwxgtk-webview3.2-dev libwxgtk-media3.2-dev 2>/dev/null && \
       echo "Additional wxWidgets 3.2 components installed" || \
       (apt-get install -y --no-install-recommends libwxgtk3.0-dev libwxgtk-webview3.0-dev libwxgtk-media3.0-dev && \
        echo "Additional wxWidgets 3.0 components installed as fallback")))) && \
    rm -rf /var/lib/apt/lists/*

# Clone the repository
WORKDIR /workspace
RUN git clone https://github.com/lgantel/bitmap2hex.git

# Set working directory to the project
WORKDIR /workspace/bitmap2hex

# Create build directory and build the project
RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    cmake --build .

# Default command (can be overridden)
CMD ["/bin/bash"]
