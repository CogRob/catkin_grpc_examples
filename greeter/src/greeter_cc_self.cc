#include <iostream>
#include <string>

#include "greeter/proto/subdir/hello_msgs.pb.h"
// -------^^^^^^^ -- Include package name if SRC_BASE is not in generate_proto

int main(int argc, char** argv) {
  catkin_grpc::greeter::HelloRequest request;
  request.set_name("CogRob");
  std::cout << request.ShortDebugString() << std::endl;
  std::cout << "Just testing protobuf." << std::endl;
  return 0;
}
