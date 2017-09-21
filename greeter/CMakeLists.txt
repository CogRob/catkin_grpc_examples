cmake_minimum_required(VERSION 2.8.3)
project(greeter)

find_package(catkin REQUIRED COMPONENTS grpc)
#---------------------------------------^^^^
# Besure to "find_package" "grpc"

catkin_package(
  CATKIN_DEPENDS grpc
)

# Generate protobuf header/library only.
generate_proto(hello_msg_proto proto/subdir/hello_msgs.proto)
# -------------^^^^^^^^^^^^^^^ -- This is a target (library) name.

# Generate protobuf header/library along with grpc header/library.
generate_proto(hello_proto GRPC proto/hello.proto)
# -------------------------^^^^ -- Also generates gRPC header/source.

# hello_proto depends on hello_msg_proto.
target_link_libraries(hello_proto hello_msg_proto)

add_executable(greeter_cc_server src/greeter_cc_server.cc)
# Links hello_proto to greeter_cc_server.
target_link_libraries(greeter_cc_server ${catkin_LIBRARIES} hello_proto)
# ----------------------------------------------------------^^^^^^^^^^^

add_executable(greeter_cc_client src/greeter_cc_client.cc)
# Links hello_proto to greeter_cc_client.
target_link_libraries(greeter_cc_client ${catkin_LIBRARIES} hello_proto)
# ----------------------------------------------------------^^^^^^^^^^^

add_executable(greeter_cc_self src/greeter_cc_self.cc)
# Links hello_msg_proto to greeter_cc_self. This does not contain gRPC.
target_link_libraries(greeter_cc_self ${catkin_LIBRARIES} hello_msg_proto)
# --------------------------------------------------------^^^^^^^^^^^^^^^

catkin_python_setup()
