#include <LibCore/ArgsParser.h>
#include <LibDNS/IDNA.h>
#include <LibUnicode/CharacterTypes.h>

ErrorOr<int> serenity_main(Main::Arguments arguments)
{
    (void)arguments;
    outln("{}", DNS::to_punycode("háčkyčárky"sv));
    return 0;
}