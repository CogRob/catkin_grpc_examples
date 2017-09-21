from __future__ import print_function

import greeter.proto.subdir.hello_msgs_pb2 as hello_msgs_pb2
# -----^^^^^^^ -- Include package name if SRC_BASE is not in generate_proto


def run():
  print(hello_msgs_pb2.HelloRequest(name='you'))
  print("Just testing protobuf")
