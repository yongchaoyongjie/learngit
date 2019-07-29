#include"httplib.h"
using namespace httplib;
static void test(const Request&req, Response&rsp){
  //rsp.set_content("<html>nihao shijie</html>","test/htm1");
  rsp.status=302;
  rsp.set_header("location","http//:www.baidu.com");
  rsp.body="<html><h1>nihao shijie</h4></html>";
  return ;
}
int main(){
 Server srv;
  srv.Get("/",test);
  srv.listen("0.0.0.0",9000);
  return 0;
}
