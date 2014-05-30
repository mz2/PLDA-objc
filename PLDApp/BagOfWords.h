#ifndef __PLDA__BagOfWords__
#define __PLDA__BagOfWords__

#include <string>
#include <vector>
#include <map>
#include <set>

#include <node.h>


namespace lda
{
    class BagOfWords : public node::ObjectWrap
{
    public:
        static void Init(v8::Handle<v8::Object> exports);
        static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);
    
        void addWord(std::string word);
        void addText(std::string text);

    private:
        ~BagOfWords();
        std::map<std::string, unsigned int> _wordCounts;

        static v8::Handle<v8::Value> New(const v8::Arguments& args);
        static v8::Persistent<v8::Function> constructor;

        BagOfWords();
    };
}

#endif
