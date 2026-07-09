class MJPEGClient
{
public:
    void begin();

    bool connect(const char *url);

    bool connected() const;

    bool readFrame();
};