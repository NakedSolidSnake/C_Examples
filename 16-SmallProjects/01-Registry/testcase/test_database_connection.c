#include <database/db.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    Database_params_t params = 
    {
        .hostname = "localhost",
        .username = "cssouza",
        .password = "senha",
        .database = "registry"
    };
    
    assert(!initdb(&params));

    assert(!closedb());
    return 0;
}
