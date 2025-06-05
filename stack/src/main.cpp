#include"stack.cpp"
#include<string>
#include<vector>
#include<ostream>

struct URL_t {

    explicit URL_t(std::string const& url_nme)
    : _name{url_nme}{}

    friend std::ostream& operator<<(std::ostream& os, URL_t const& url){ // My friend can access to private members.
        os<<url._name;
        return os;
    }

private:
    std::string _name{};
};

int
main(void)
{
    TDA::Stack_t<URL_t> stack{};
    std::vector<std::string> url_names {
        "https://portal.uv.cl/loginPrincipal2/",
        "https://portalalumnospregrado.uv.cl/?uid=???",
        "https://aulavirtualpregrado.uv.cl/my/",
        "https://aulavirtualpregrado.uv.cl/course/view.php?id=structura_datos",
        "https://aulavirtualpregrado.uv.cl/mod/folder/view.php?id=ayudantia"
    };

    for (auto const& url_name :  url_names){
        stack.push(URL_t{url_name});
        stack.show();
    }
    
    auto const* val = stack.get();
    std::cout<<"First in stack: "<<*val<<"\n";

    stack.pop();
    stack.show();
    val = stack.get();
    std::cout<<"First in stack: "<<*val<<"\n";

    while(stack.size())
    {
        stack.pop();
        stack.show();
    }

    return 0;
}