#include <nan.h>

typedef struct TSLanguage TSLanguage;

extern "C" TSLanguage *tree_sitter_plantuml();

static void Init(v8::Local<v8::Object> exports) {
  // tree-sitter (the JS runtime) expects the language object to be a V8 object
  // with exactly one internal field containing a `TSLanguage*`.
  v8::Local<v8::ObjectTemplate> language_template = Nan::New<v8::ObjectTemplate>();
  language_template->SetInternalFieldCount(1);
  v8::Local<v8::Object> language = Nan::NewInstance(language_template).ToLocalChecked();
  Nan::SetInternalFieldPointer(language, 0, tree_sitter_plantuml());

  Nan::Set(exports, Nan::New("name").ToLocalChecked(), Nan::New("plantuml").ToLocalChecked());
  Nan::Set(exports, Nan::New("language").ToLocalChecked(), language);
}

NODE_MODULE(tree_sitter_plantuml_binding, Init)
