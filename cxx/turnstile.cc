#include <node.h>
#include <v8.h>

#include <string>
using namespace std;

string get_icbc_ver();
string test_cpp();
int init_icbc();
using namespace v8;
void get_ver(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  args.GetReturnValue().Set( String::NewFromUtf8(isolate, get_icbc_ver().c_str() ) );    
}
void test_cpp(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  args.GetReturnValue().Set( String::NewFromUtf8(isolate, test_cpp().c_str() ) );    
}
Persistent<Function> qr_cb;
void openGate(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "open gate"));
  
  const unsigned argc = 1;
  Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "gate open callback") };
  Local<Function>::New(isolate, qr_cb)->Call(isolate->GetCurrentContext()->Global(), argc, argv);
  
}
void regQR(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  qr_cb.Reset( isolate, args[0].As<Function>() );
  const unsigned argc = 1;
  Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "get qr code") };
  Local<Function>::New(isolate, qr_cb)->Call(isolate->GetCurrentContext()->Global(), argc, argv);
  //callback.Reset();
}
void load_dll(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  //double value = args[0]->NumberValue() + args[1]->NumberValue();
  int iret = init_icbc();
  Local<Number> ret = Number::New(isolate, iret);
  args.GetReturnValue().Set(ret);
}


  
void Init(Handle<Object> exports, Handle<Object> module) {
  Isolate* isolate = Isolate::GetCurrent();
  exports->Set(String::NewFromUtf8(isolate, "openGate"),
      FunctionTemplate::New(isolate, openGate)->GetFunction());
  exports->Set(String::NewFromUtf8(isolate, "regQR"),
      FunctionTemplate::New(isolate, regQR)->GetFunction());
  exports->Set(String::NewFromUtf8(isolate, "get_ver"),
      FunctionTemplate::New(isolate, get_ver)->GetFunction());
  exports->Set(String::NewFromUtf8(isolate, "load_dll"),
      FunctionTemplate::New(isolate, load_dll)->GetFunction());
  exports->Set(String::NewFromUtf8(isolate, "test_cpp"),
      FunctionTemplate::New(isolate, test_cpp)->GetFunction());
}

NODE_MODULE(turnstile, Init)
