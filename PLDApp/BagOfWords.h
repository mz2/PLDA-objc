#ifndef __PLDA__LDAModel__
#define __PLDA__LDAModel__

#include <string>
#include <vector>

#include <node.h>


namespace lda
{
    class BagOfWords : public node::ObjectWrap
{
    public:
        static void Init(v8::Handle<v8::Object> exports);
        static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);

    private:
        ~BagOfWords();
        std::vector<std::string> _corpus;
        std::vector<std::string> _inference;

        static v8::Handle<v8::Value> New(const v8::Arguments& args);
        static v8::Persistent<v8::Function> constructor;

        BagOfWords();
    };
}

#endif
