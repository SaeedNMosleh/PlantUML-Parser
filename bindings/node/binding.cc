#include <napi.h>

typedef struct TSLanguage TSLanguage;

extern "C" TSLanguage *tree_sitter_plantuml();

namespace {

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports["name"] = Napi::String::New(env, "plantuml");
  auto language = reinterpret_cast<Napi::External<TSLanguage>::Finalizer>(tree_sitter_plantuml);
  exports["language"] = Napi::External<TSLanguage>::New(env, tree_sitter_plantuml(), language);
  return exports;
}

NODE_API_MODULE(tree_sitter_plantuml_binding, Init)

}  // namespace
