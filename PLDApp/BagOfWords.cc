#include <string>
#include <map>
#include <stdio.h>

#include "lda.h"

#include "BagOfWords.h"

#include <node.h>


using namespace v8;

namespace lda
{
    BagOfWords::BagOfWords() {
        _wordCounts = std::map<std::string, unsigned int>();
    }
    
    BagOfWords::~BagOfWords() {
    }
    
    Persistent<Function> BagOfWords::constructor;
    
    void BagOfWords::Init(Handle<Object> exports) {
        // Prepare constructor template
        Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
        tpl->SetClassName(String::NewSymbol("BagOfWords"));
        tpl->InstanceTemplate()->SetInternalFieldCount(1);
        
        constructor = Persistent<Function>::New(tpl->GetFunction());
        exports->Set(String::NewSymbol("BagOfWords"), constructor);
    }
    
    Handle<Value> BagOfWords::New(const Arguments& args) {
        HandleScope scope;
        
        if (args.IsConstructCall()) {
            BagOfWords *obj = new BagOfWords();
            obj->Wrap(args.This());
            return args.This();
        } else {
            return scope.Close(constructor->NewInstance());
        }
    }
    
    Handle<Value> BagOfWords::NewInstance(const Arguments& args) {
        HandleScope scope;
        Local<Object> instance = constructor->NewInstance();
        return scope.Close(instance);
    }
}