#include "../include/quadTree.h"

namespace quadtree
{
    void QuadTree::init_tree(std::vector<particle_sys::Body>& bin, int n)
    // we take an empty bin of particles, and a number of desired particles
    // insert particles into a tree
    // then we build leafs of tree
    {
        if (bin.size() == 0){
            particle_sys::init_particles(bin,n);
        }

        if (this->m_root == nullptr) {
            Box temp = Box(Point{-1.0*_pWidth,_pHeight}, Point{_pWidth,-1.0*_pHeight});
            // std::cout << "root box:\n";
            // std::cout << "TL: " << temp.tl << '\n';
            // std::cout << "BR: " << temp.br << '\n' << '\n';
            this->m_root = new Node{bin,temp,nullptr};
            if (bin.size() > 1) {
                std::cout << "bin size: " << bin.size() << '\n';
                for (particle_sys::Body b : bin) {
                    std::cout << "inserting body\n";
                    //if (b.is_center == false) { 
                        insert(m_root,b); 
                    //}
                }
            }
        }
    }

    void QuadTree::insert(Node* root, particle_sys::Body& b)
    {
        Node* ptr = root;
        // if node exists
        if (ptr != nullptr) {

            // then for each child node operate loop
            for (int i = 0; i < 4; i++) {

                // generate the respective parent's children nodes
                if (ptr->quad[i] == nullptr) {
                    Box temp = create_box(ptr,i);
                    ptr->quad[i] = new Node(temp,ptr);
                }

                // if body is inside child's box then add to child's bin
                if (in_boundary(ptr->quad[i]->m_box,Point{b.x,b.y})) {
                    ptr->quad[i]->m_bin.push_back(b);
                    std::cout << "      >putting into quadrant: " << i+1 << "\n";
                    
                    // if child holds more than one body then generate children
                    if (ptr->quad[i]->m_bin.size() > 1) {
                        ptr = ptr->quad[i];
                        std::cout << "          >>this child holds multiple bodies, need to divide box\n";
                        insert(ptr,b);
                    }
                    // otherwise return and insert next body into the tree
                    return;
                }
            }
        } else {
            std::cout << "something else is happening\n";
            return;
        }
        return;
    }

    bool in_boundary(Box b, Point p) 
    { 
        // std::cout << "TL: " << b.tl << '\n';
        // std::cout << "BR: " << b.br << '\n';
        // std::cout << "Point: " << p << '\n';
        return (p.x >= b.tl.x && p.x <= b.br.x && 
                p.y >= b.br.y && p.y <= b.tl.y); 
    }

    Box create_box(Node* parent, int quad) 
    {
        Point _tl, _br;
        switch(quad){
            case 0:
                return Box(parent->m_box.tl, parent->m_box.center);
            case 1:
                _tl = Point{((parent->m_box.tl.x + parent->m_box.br.x) / 2.0), parent->m_box.tl.y};
                _br = Point{parent->m_box.br.x, ((parent->m_box.tl.y + parent->m_box.br.y) / 2.0)};
                return Box(_tl,_br);
            case 2:
                _tl = Point{parent->m_box.tl.x, ((parent->m_box.tl.y + parent->m_box.br.y) / 2.0)};
                _br = Point{((parent->m_box.tl.x + parent->m_box.br.x) / 2.0), parent->m_box.br.y};
                return Box(_tl,_br);
            case 3:
                return Box(parent->m_box.center,parent->m_box.br);
            default:
                return Box(Point{0,1},Point{1,0});
        }
    }

    // void QuadTree::insert(particle_sys::Body& j, Node* n)
    // /* TODO */
    // {
    //     // if node is NULL, return
    //     if (n == NULL) return;
    //     // current quad cannot contain it, return
    //     if(!in_boundary(Point{j.x,j.y}, *n)) { return; }
    //     // else add body to node
    //     else { n->node_bin.push_back(j); }
    // }

    void print_node_bin(Node* n)
    {
        for (particle_sys::Body b : n->m_bin) {
            std::cout << b.x << ", " << b.y << '\n';
        }
    }
} // namespace quadtree



