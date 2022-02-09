#include <iostream>

#ifdef __EMSCRIPTEN__

#include <emscripten.h>

#endif

#ifdef __cplusplus
extern "C"{
#endif

typedef void (*publish_func)(const char* topic, const char* payload);

publish_func EMSCRIPTEN_KEEPALIVE publish = NULL;

void EMSCRIPTEN_KEEPALIVE setPublishFunction(publish_func _publish)
{
    publish = _publish;
}

void EMSCRIPTEN_KEEPALIVE onConnected()
{
    std::cout<<"c++ connected!"<<std::endl;
}

void EMSCRIPTEN_KEEPALIVE onDisconnected()
{
    std::cout<<"disconnected!";
}
 
void EMSCRIPTEN_KEEPALIVE onMessageReceived(const char* topic, const char* payload){
    std::cout<<"recv msg topic:"<<topic<<" payload:"<<payload<<std::endl;
    publish("testx", "cpp publish!");
}

int main(int argc, char** argv){
    std::cout<<"Hello WASM"<<std::endl;
    return 0;
}

#ifdef __cplusplus
}
#endif