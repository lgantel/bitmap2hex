# bitmap2hex
Application to convert a Bitmap into an hex array

## Docker

### Build the Docker image
```bash
docker build -t bitmap2hex .
```

### Run the container
```bash
docker run -it --rm bitmap2hex
```

### Run the container with GUI support (for wxWidgets applications)

Before running the container, allow local X11 connections:
```bash
xhost +local:root
```

Then run the container with X11 socket and display forwarding:
```bash
docker run -it --rm \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    --net=host \
    bitmap2hex
```

After finishing, revoke the X11 access:
```bash
xhost -local:root
```
