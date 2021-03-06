#include "HTMLElement.h"

namespace Newtoo
{

    HTMLElement::HTMLElement()
    {}

    HTMLElement::HTMLElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :Element(aNamespace, qualifiedName, aPrefix)
    {}

    Node* HTMLElement::cloneNode(bool deep)
    {
        return new HTMLElement(*this, deep);
    }

    DOMString HTMLElement::innerText()
    {
        return textContent();
    }
    void HTMLElement::setInnerText(DOMString aInnerText)
    {
        setTextContent(aInnerText);
    }

    HTMLElement::ElementKind HTMLElement::getElementKind()
    {
        return ElementKind::HTMLElement;
    }

    DOMString HTMLElement::contentEditable()
    {
        return getAttribute("contenteditable");
    }
    void HTMLElement::setContentEditable(DOMString aContentEditable)
    {
        return setAttribute("contenteditable", aContentEditable);
    }
    bool HTMLElement::isContentEditable()
    {
        return contentEditable() == "true";
    }

    HTMLSemanticElement::HTMLSemanticElement()
    {}

    HTMLSemanticElement::HTMLSemanticElement(DOMString aNamespace, DOMString qualifiedName,
                                             DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLSemanticElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "block", UAPropertyPriority);
        return st;
    }

    Node* HTMLSemanticElement::cloneNode(bool deep)
    {
        return new HTMLSemanticElement(*this, deep);
    }

}
