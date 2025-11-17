#include "symtable.h"

SymTable::SymTable() : prev(nullptr) {}

SymTable::SymTable(SymTable * t) : prev(t) {}

bool SymTable::Insert(string s, Symbol symb) 
{ 
    auto result = table.insert({s, symb});
    return result.second;  // second = true si se inserto
}

Symbol * SymTable::Find(string s) 
{
    for (SymTable * st = this; st != nullptr; st = st->prev) 
    {
        auto found = st->table.find(s);
        if (found != st->table.end()) 
            return &found->second;
    }
    return nullptr;
}