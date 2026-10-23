// g++ main.cpp -o main.exe
// .\main.exe


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Convert special characters into safe HTML text
string escapeHTML(string text) {
    string result;

    for (int i = 0; i < (int)text.length(); i++) {
        switch (text[i]) {
            case '&': result += "&amp;"; break;
            case '<': result += "&lt;"; break;
            case '>': result += "&gt;"; break;
            case '"': result += "&quot;"; break;
            case '\'': result += "&#39;"; break;
            default: result += text[i];
        }
    }

    return result;
}

int main() {
    string name, role, about, skills, education;
    string projectTitle, projectDescription;
    string email, github, linkedin;

    cout << "\n====================================\n";
    cout << "     PROFESSIONAL PORTFOLIO BUILDER\n";
    cout << "====================================\n\n";

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your professional role: ";
    getline(cin, role);

    cout << "Write your About Me paragraph: ";
    getline(cin, about);

    cout << "Enter skills separated by commas: ";
    getline(cin, skills);

    cout << "Enter your education: ";
    getline(cin, education);

    cout << "Enter your project title: ";
    getline(cin, projectTitle);

    cout << "Describe your project: ";
    getline(cin, projectDescription);

    cout << "Enter your email: ";
    getline(cin, email);

    cout << "Enter your GitHub URL (or leave blank): ";
    getline(cin, github);

    cout << "Enter your LinkedIn URL (or leave blank): ";
    getline(cin, linkedin);

    // Create HTML file
    ofstream html("index.html");

    if (!html) {
        cout << "Error creating index.html!" << endl;
        return 1;
    }

    html << R"HTML(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
)HTML";

    html << "    <title>" << escapeHTML(name)
         << " | Portfolio</title>\n";

    html << R"HTML(    <meta name="description"
          content="Personal portfolio website">
    <link rel="stylesheet" href="style.css">
</head>
<body>

    <nav class="navbar">
        <a class="logo" href="#home">Portfolio<span>.</span></a>

        <div class="nav-links">
            <a href="#about">About</a>
            <a href="#skills">Skills</a>
            <a href="#projects">Projects</a>
            <a href="#education">Education</a>
            <a href="#contact">Contact</a>
        </div>
    </nav>

    <main>
        <section class="hero" id="home">
            <div class="hero-content">
                <p class="eyebrow">WELCOME TO MY PORTFOLIO</p>
                <h1>Hello, I'm <span>)HTML";

    html << escapeHTML(name);

    html << R"HTML(</span></h1>
                <h2>)HTML";

    html << escapeHTML(role);

    html << R"HTML(</h2>
                <p class="hero-description">)HTML";

    html << escapeHTML(about);

    html << R"HTML(</p>

                <div class="hero-buttons">
                    <a class="btn btn-primary" href="#projects">
                        Explore My Work
                    </a>
                    <a class="btn btn-outline" href="#contact">
                        Contact Me
                    </a>
                </div>
            </div>

            <div class="hero-decoration">
                <div class="orbit orbit-one"></div>
                <div class="orbit orbit-two"></div>
                <div class="center-symbol">&lt;/&gt;</div>
            </div>
        </section>

        <section class="section" id="about">
            <div class="section-heading">
                <p class="eyebrow">GET TO KNOW ME</p>
                <h2>About <span>Me</span></h2>
            </div>

            <div class="about-card">
                <div class="about-mark">&lt;/&gt;</div>
                <div>
                    <h3>A little about myself</h3>
                    <p>)HTML";

    html << escapeHTML(about);

    html << R"HTML(</p>
                </div>
            </div>
        </section>

        <section class="section section-muted" id="skills">
            <div class="section-heading">
                <p class="eyebrow">WHAT I WORK WITH</p>
                <h2>My <span>Skills</span></h2>
                <p>Technologies and skills I am learning and using.</p>
            </div>

            <div class="skills-grid">
)HTML";

    // Convert comma-separated skills into individual tags
    stringstream skillStream(skills);
    string skill;

    while (getline(skillStream, skill, ',')) {
        size_t first = skill.find_first_not_of(" \t");
        size_t last = skill.find_last_not_of(" \t");

        if (first != string::npos) {
            skill = skill.substr(first, last - first + 1);

            html << "                <div class=\"skill-card\">"
                 << escapeHTML(skill)
                 << "</div>\n";
        }
    }

    html << R"HTML(            </div>
        </section>

        <section class="section" id="projects">
            <div class="section-heading">
                <p class="eyebrow">WHAT I'VE BUILT</p>
                <h2>Featured <span>Project</span></h2>
            </div>

            <article class="project-card">
                <div class="project-visual">
                    <span>&lt;/&gt;</span>
                </div>

                <div class="project-content">
                    <p class="project-label">FEATURED PROJECT</p>
                    <h3>)HTML";

    html << escapeHTML(projectTitle);

    html << R"HTML(</h3>
                    <p>)HTML";

    html << escapeHTML(projectDescription);

    html << R"HTML(</p>
                    <span class="project-tech">C++ / HTML / CSS</span>
                </div>
            </article>
        </section>

        <section class="section section-muted" id="education">
            <div class="section-heading">
                <p class="eyebrow">MY LEARNING JOURNEY</p>
                <h2>My <span>Education</span></h2>
            </div>

            <div class="education-card">
                <div class="education-icon">&#9733;</div>
                <div>
                    <h3>Education & Learning</h3>
                    <p>)HTML";

    html << escapeHTML(education);

    html << R"HTML(</p>
                </div>
            </div>
        </section>

        <section class="section contact-section" id="contact">
            <div class="section-heading">
                <p class="eyebrow">LET'S CONNECT</p>
                <h2>Get In <span>Touch</span></h2>
                <p>Have a question or want to work together? Reach out.</p>
            </div>

            <a class="btn btn-primary email-btn" href="mailto:)HTML";

    html << escapeHTML(email);

    html << R"HTML(">
                Email Me
            </a>

            <div class="social-links">
)HTML";

    if (!github.empty()) {
        html << "                <a href=\""
             << escapeHTML(github)
             << "\" target=\"_blank\" rel=\"noopener noreferrer\">GitHub</a>\n";
    }

    if (!linkedin.empty()) {
        html << "                <a href=\""
             << escapeHTML(linkedin)
             << "\" target=\"_blank\" rel=\"noopener noreferrer\">LinkedIn</a>\n";
    }

    html << R"HTML(            </div>
        </section>
    </main>

    <footer>
        <p>&copy; 2026 )HTML";

    html << escapeHTML(name);

    html << R"HTML(. Built with my C++ Website Generator.</p>
    </footer>

</body>
</html>
)HTML";

    html.close();

    // Create the CSS stylesheet
    ofstream css("style.css");

    if (!css) {
        cout << "Error creating style.css!" << endl;
        return 1;
    }

    css << R"CSS(* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

html {
    scroll-behavior: smooth;
    scroll-padding-top: 90px;
}

body {
    font-family: "Segoe UI", Arial, sans-serif;
    background: #0b1020;
    color: #f1f5f9;
    line-height: 1.7;
}

a {
    color: inherit;
}

.navbar {
    position: sticky;
    top: 0;
    z-index: 100;
    display: flex;
    justify-content: space-between;
    align-items: center;
    gap: 24px;
    padding: 18px 8%;
    background: rgba(11, 16, 32, 0.96);
    border-bottom: 1px solid #252c43;
}

.logo {
    color: #ffffff;
    font-size: 24px;
    font-weight: 800;
    text-decoration: none;
}

.logo span,
h1 span,
h2 span {
    color: #a78bfa;
}

.nav-links {
    display: flex;
    flex-wrap: wrap;
    gap: 22px;
}

.nav-links a {
    color: #cbd5e1;
    font-size: 14px;
    text-decoration: none;
    transition: color 0.2s;
}

.nav-links a:hover,
.social-links a:hover {
    color: #a78bfa;
}

.hero {
    min-height: 570px;
    display: flex;
    align-items: center;
    justify-content: space-between;
    gap: 40px;
    padding: 85px 10%;
    background:
        radial-gradient(ellipse at 80% 30%,
        #252052 0%, #0b1020 55%);
}

.hero-content {
    max-width: 660px;
}

.eyebrow {
    color: #a78bfa;
    font-size: 12px;
    font-weight: 800;
    letter-spacing: 3px;
    margin-bottom: 12px;
}

.hero h1 {
    font-size: clamp(38px, 6vw, 64px);
    line-height: 1.15;
    margin-bottom: 16px;
    overflow-wrap: anywhere;
}

.hero h2 {
    color: #cbd5e1;
    font-size: clamp(20px, 3vw, 28px);
    font-weight: 500;
    margin-bottom: 18px;
}

.hero-description {
    max-width: 580px;
    color: #aab5ca;
    margin-bottom: 28px;
}

.hero-buttons {
    display: flex;
    flex-wrap: wrap;
    gap: 14px;
}

.btn {
    display: inline-block;
    padding: 12px 22px;
    border: 1px solid transparent;
    border-radius: 8px;
    font-weight: 700;
    text-decoration: none;
    transition: transform 0.2s, background 0.2s;
}

.btn:hover {
    transform: translateY(-3px);
}

.btn-primary {
    background: #7c3aed;
    color: #ffffff;
}

.btn-primary:hover {
    background: #6d28d9;
}

.btn-outline {
    border-color: #555078;
    color: #ffffff;
}

.btn-outline:hover {
    background: #252052;
}

.hero-decoration {
    position: relative;
    width: 230px;
    height: 230px;
    flex-shrink: 0;
    display: grid;
    place-items: center;
}

.orbit {
    position: absolute;
    border: 1px solid #5b4ca5;
    border-radius: 50%;
}

.orbit-one {
    width: 230px;
    height: 230px;
}

.orbit-two {
    width: 165px;
    height: 165px;
    border-style: dashed;
}

.center-symbol {
    display: grid;
    place-items: center;
    width: 110px;
    height: 110px;
    border-radius: 28px;
    background: linear-gradient(135deg, #7c3aed, #4338ca);
    font-size: 32px;
    font-weight: 800;
    box-shadow: 0 0 55px #7c3aed55;
}

.section {
    padding: 85px 10%;
    scroll-margin-top: 70px;
}

.section-muted {
    background: #10172a;
}

.section-heading {
    max-width: 720px;
    margin: 0 auto 40px;
    text-align: center;
}

.section-heading h2 {
    font-size: clamp(30px, 4vw, 42px);
    line-height: 1.25;
    margin-bottom: 12px;
}

.section-heading > p:not(.eyebrow) {
    color: #aab5ca;
}

.about-card,
.education-card {
    display: flex;
    align-items: flex-start;
    gap: 22px;
    max-width: 850px;
    margin: auto;
    padding: 30px;
    background: #151d32;
    border: 1px solid #28324b;
    border-radius: 16px;
}

.about-card h3,
.education-card h3 {
    margin-bottom: 8px;
    font-size: 21px;
}

.about-card p,
.education-card p {
    color: #aab5ca;
    overflow-wrap: anywhere;
}

.about-mark,
.education-icon {
    display: grid;
    place-items: center;
    flex-shrink: 0;
    width: 55px;
    height: 55px;
    border-radius: 12px;
    background: #2b2053;
    color: #c4b5fd;
    font-size: 20px;
    font-weight: 800;
}

.skills-grid {
    display: grid;
    grid-template-columns: repeat(3, minmax(0, 1fr));
    gap: 18px;
    max-width: 900px;
    margin: auto;
}

.skill-card {
    padding: 24px 16px;
    text-align: center;
    overflow-wrap: anywhere;
    background: #151d32;
    border: 1px solid #2a3450;
    border-radius: 12px;
    font-weight: 700;
    transition: border-color 0.2s, transform 0.2s;
}

.skill-card:hover {
    border-color: #8b5cf6;
    transform: translateY(-4px);
}

.project-card {
    display: grid;
    grid-template-columns: 0.8fr 1.2fr;
    max-width: 900px;
    margin: auto;
    overflow: hidden;
    background: #151d32;
    border: 1px solid #28324b;
    border-radius: 16px;
}

.project-visual {
    display: grid;
    place-items: center;
    min-height: 260px;
    background: linear-gradient(135deg, #312e81, #7c3aed);
}

.project-visual span {
    font-size: 52px;
    font-weight: 800;
}

.project-content {
    padding: 30px;
}

.project-label {
    color: #a78bfa;
    font-size: 11px;
    font-weight: 800;
    letter-spacing: 2px;
}

.project-content h3 {
    margin: 10px 0;
    font-size: 25px;
    overflow-wrap: anywhere;
}

.project-content > p:not(.project-label) {
    color: #aab5ca;
    overflow-wrap: anywhere;
}

.project-tech {
    display: inline-block;
    margin-top: 20px;
    padding: 6px 12px;
    border-radius: 20px;
    background: #2b2053;
    color: #c4b5fd;
    font-size: 12px;
}

.contact-section {
    text-align: center;
    background: radial-gradient(ellipse at center, #211b48, #0b1020 70%);
}

.email-btn {
    margin: 0 auto 20px;
}

.social-links {
    display: flex;
    justify-content: center;
    flex-wrap: wrap;
    gap: 22px;
    margin-top: 12px;
}

.social-links a {
    color: #cbd5e1;
    text-decoration: none;
}

footer {
    padding: 24px 5%;
    text-align: center;
    color: #94a3b8;
    background: #080c18;
    border-top: 1px solid #252c43;
    font-size: 13px;
}

@media (max-width: 800px) {
    .navbar {
        flex-direction: column;
        padding: 16px 5%;
    }

    .nav-links {
        justify-content: center;
        gap: 10px 18px;
    }

    .hero {
        min-height: auto;
        flex-direction: column;
        text-align: center;
        padding: 70px 7%;
    }

    .hero-buttons {
        justify-content: center;
    }

    .hero-decoration {
        width: 170px;
        height: 170px;
    }

    .orbit-one {
        width: 170px;
        height: 170px;
    }

    .orbit-two {
        width: 125px;
        height: 125px;
    }

    .center-symbol {
        width: 85px;
        height: 85px;
        font-size: 26px;
    }

    .section {
        padding: 65px 7%;
    }

    .skills-grid {
        grid-template-columns: repeat(2, minmax(0, 1fr));
    }
}

@media (max-width: 520px) {
    .skills-grid {
        grid-template-columns: 1fr;
    }

    .project-card {
        grid-template-columns: 1fr;
    }

    .project-visual {
        min-height: 150px;
    }

    .about-card,
    .education-card {
        flex-direction: column;
        padding: 22px;
    }

    .hero h1 {
        font-size: 38px;
    }
}
)CSS";

    css.close();

    cout << "\n====================================\n";
    cout << "  PORTFOLIO GENERATED SUCCESSFULLY!\n";
    cout << "====================================\n";
    cout << "Created: index.html\n";
    cout << "Created: style.css\n";
    cout << "Open index.html in your browser.\n";

    return 0;
}



