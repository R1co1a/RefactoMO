#include <list>
#include <vector>

class storage_type {
    public:
        virtual ~storage_type();
        virtual void push_back(double value);
        virtual void clear_list();
        virtual double get_value(size_t index) const;
        virtual size_t size () const;
};

class list_storage : public storage_type {
    private:
        std::list<double> data;
    public:
        void push_back(double value)override;
        void clear_list()override;
        double get_value(size_t index) const override;
        size_t size() const override;
};

class vector_storage : public storage_type{
    private:
        std::vector<double> data;
    public:
        void push_back(double value)override;
        void clear_list()override;
        double get_value(size_t index) const override;
        size_t size() const override;
};