set(SOURCES
    Answer.cpp
    Name.cpp
    Packet.cpp
    IDNA.cpp
)

serenity_lib(LibDNS dns)
target_link_libraries(LibDNS LibC)
