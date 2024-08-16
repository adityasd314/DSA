const jsdom = require("jsdom");
const { JSDOM } = jsdom;

const query = "National Education Policy"; // Replace this with your search query
const googleSearchUrl = `https://www.google.com/search?q=${encodeURIComponent(query)}`;
console.log({googleSearchUrl})
async function fetchGoogleSearch(url) {
  try {
    const response = await fetch(url, {
      headers: {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36",
      },
    });

    if (!response.ok) {
      throw new Error(`Failed to fetch data: ${response.statusText}`);
    }

    const html = await response.text();
    return html;
  } catch (error) {
    console.error("Error fetching Google search page:", error);
    throw error;
  }
}
function extractPeopleAlsoAsk(html) {
    const dom = new JSDOM(html);
    const document = dom.window.document;
  
    // Find the element that contains "People also ask"
    const paaHeader = Array.from(document.querySelectorAll('h2')).find(
      (el) => el.textContent.trim().toLowerCase() === 'people also ask'
    );
  
    if (!paaHeader) {
      throw new Error("People also ask section not found");
    }
  
    // Find the closest parent container that holds the questions
    let questionsContainer = paaHeader.closest('div');
    if (!questionsContainer) {
      throw new Error("Questions container not found");
    }
  
    const questions = [];
    questionsContainer.querySelectorAll('div[jsname="Cpkphb"]').forEach(element => {
      const question = element.textContent.trim();
      if (question) {
        questions.push(question);
      }
    });
  
    return questions;
  }
  
  (async () => {
    try {
      const html = await fetchGoogleSearch(googleSearchUrl);
      const questions = extractPeopleAlsoAsk(html);
  
      console.log("People Also Ask Questions:");
      questions.forEach((question, index) => {
        console.log(`${index + 1}. ${question}`);
      });
    } catch (error) {
      console.error("Error:", error);
    }
  })();